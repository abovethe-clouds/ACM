#include <bits/stdc++.h>
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
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    ll a[101][101] = {};
    ll dp[101][101][5505] = {};
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            for (int o = 0; o < 5505; o++)
            {
                dp[i][j][o] = -4e9;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int o = 0; o <= k; o++)
            {
                if (o == 0)
                    dp[i][j][o] = max(dp[i - 1][j - 1][o], dp[i - 1][j][o]) + a[i][j];
                else
                {
                    dp[i][j][o] = max(dp[i - 1][j - 1][o - 1], dp[i - 1][j][o - 1]) + a[i][j] * 3;
                    dp[i][j][o] = max(dp[i][j][o], max(dp[i - 1][j][o], dp[i - 1][j - 1][o]) + a[i][j]);
                }
            }
        }
    }
    ll maxx = LONG_LONG_MIN;
    for (int j = 1; j <= n; j++)
    {
        for (int o = 0; o <= k; o++)
            maxx = max(maxx, dp[n][j][o]);
    }
    cout << maxx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}