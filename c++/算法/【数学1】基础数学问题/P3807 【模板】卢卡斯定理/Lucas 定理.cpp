#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define int ll
const int inf = 0x3f3f3f3f, P = 131, maxn = 1e5 + 5;
int mod;
int f[maxn], g[maxn];
int my_C(int n, int m)
{
    if (m < 0 || m > n)
        return 0;
    return f[n] * g[m] * g[n - m] % mod;
}
int lucas(int n, int m)
{
    if (m == 0)
        return 1;
    return lucas(n / mod, m / mod) * my_C(n % mod, m % mod) % mod;
}
int fast_pow(int a, int b, int p)
{
    a %= p;
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % p;
        }
        a = a * a % p;
        b /= 2;
    }
    return ans;
}
void jisuan(int n)
{
    f[0] = g[0] = 1;
    for (int i = 1; i < n; i++)
    {
        f[i] = f[i - 1] * i % mod;
        g[i] = g[i - 1] * fast_pow(i, mod - 2, mod) % mod;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m >> mod;
        jisuan(mod);
        cout << lucas(n + m, m) << endl;
    }

    return 0;
}