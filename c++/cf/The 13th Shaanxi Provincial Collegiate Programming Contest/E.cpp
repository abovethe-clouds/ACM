#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
//#define int ll
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;

int read()
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

int n, m, t;
string s;
int dp[21][1 << 20];
int num_1[1 << 20] = {};
int ch[27][27] = {};

pii move(int pos, int have, int will)
{
    int print = num_1[((1 << will) - 1) & have];
    return {abs(pos - print), print};
}

int dfs(int pos, int have, int pre)
{
    if (dp[pos][have] != -1)
        return dp[pos][have];
    if (have == (1 << n) - 1)
        return 0;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (!(have >> i & 1))
        {
            int c = s[i] - 'a';
            int print = ch[pre][c] + t;
            pii x = move(pos, have, i);
            int move1 = x.first;
            int move_cost = move1 * t;
            ans = min(ans, dfs(x.second + 1, have | (1 << i), c) + print + move_cost);
        }
    }
    return dp[pos][have] = ans;
}

void num()
{
    for (int i = 1; i < 1 << 20; i++)
    {
        num_1[i] = num_1[i >> 1] + (i & 1);
    }
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    num();
    cin >> n >> m >> t;
    cin >> s;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> ch[i][j];
    }
    cout << dfs(0, 0, 0);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;

    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 2025/9/2.
//
