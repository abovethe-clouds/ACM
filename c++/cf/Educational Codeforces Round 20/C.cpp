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
#define int ull
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

void solve()
{
    const int n = read(), k = read();
    if (k == 1)
    {
        cout << n << endl;
        return;
    }
    if (k>1e9)
    {
        cout << -1 << endl;
        return;
    }
    if (k >= n)
    {
        cout << -1 << endl;
        return;
    }
    if (k * (k + 1) / 2 > n)
    {
        cout << -1 << endl;
        return;
    }
    int max_gcd_lim = 2 * n / (k * (k + 1)), max_gcd = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i <= max_gcd_lim) max_gcd = max(i, max_gcd);
            if (n / i <= max_gcd_lim) max_gcd = max(n / i, max_gcd);
        }
    }
    if (max_gcd == 0)
    {
        cout << "-1" << endl;
        return;
    }
    int sum = n / max_gcd;
    for (int i = 1; i < k; i++)
    {
        cout << i * max_gcd << " ";
        sum -= i;
    }
    cout << sum * max_gcd << endl;
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
    //cin >> t;
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 25-8-19.
//
