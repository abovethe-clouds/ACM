#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
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

int n;
int mp[100005];
int dp[100005][500];

int dfs(int p, int k)
{
    if (p > n)
        return 0;
    if (dp[p][k] != 0)
        return dp[p][k];
    return dp[p][k] = 1 + dfs(p + mp[p] + k, k);
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        mp[i] = read();
    int q = read();
    for (int i = 1; i <= q; i++)
    {
        int p = read(), k = read();
        if (k > sqrt(n))
        {
            int cnt = 0;
            while (p <= n)
            {
                p = p + mp[p] + k;
                cnt++;
            }
            cout << cnt << endl;
        } else
        {
            cout << dfs(p, k) << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 25-8-19.
//
