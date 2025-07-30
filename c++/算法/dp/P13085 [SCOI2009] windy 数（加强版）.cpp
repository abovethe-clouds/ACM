#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
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

int a[20] = {};
int dp[20][20][2][2] = {};
int cnt;

int dfs(int i, int front, bool free, bool _0) //i 从高到底处理到第i位数 free=1 自由 _0=1前面都是0
{
    if (i == 0) return (_0 == 1 ? 0 : 1);
    if (dp[i][front][free][_0] != 0)// 如果有结果，返回结果
            return dp[i][front][free][_0];
    int sum = 0;//结果
    if (_0)
        sum += dfs(i - 1, 19, 1, 1);//这一位填0（前缀
    else  if (front > 1)
        sum += dfs(i - 1, 0, free||(a[i]!=0), 0);//这位填0
    if (free)
    {
        for (int j = 1; j <= 9; j++)
            if (abs(j - front) >= 2)
                sum += dfs(i - 1, j, 1, 0);
    } else
    {
        for (int j = 1; j <= a[i]; j++)
        {
            if (j == a[i] && abs(j - front) >= 2)
                sum += dfs(i - 1, j, 0, 0);
            else if (abs(j - front) >= 2)
                sum += dfs(i - 1, j, 1, 0);
        }
    }
    dp[i][front][free][_0] = sum;
    return dp[i][front][free][_0];
}

int sol(int x)
{
    memset(dp, 0, sizeof(dp));
    memset(a, 0, sizeof(a));
    cnt = 0;
    while (x)
    {
        a[++cnt] = x % 10;
        x /= 10;
    }
    return dfs(cnt, 19, 0, 1);
}

void solve()
{
    int l, r;
    cin >> l >> r;
    cout << sol(r) - sol(l - 1) << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 25-7-30.
//
