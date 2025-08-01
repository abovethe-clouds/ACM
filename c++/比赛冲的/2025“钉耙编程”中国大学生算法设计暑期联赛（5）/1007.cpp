#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn = 1e5 + 5;
int f[maxn],g[maxn];
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
ll fast_pow(ll base, ll exp)
{
    ll ret = 1;
    while (exp > 0)
    {
        if (exp & 1)
        {
            ret *= base;
            ret %= mod;
        }
        exp >>= 1;
        base *= base;
        base %= mod;
    }
    return ret;
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    // ll ans=0;
    // for(int i=1;i<m;i++)
    // {
    //     ans+=i*C(n-i-1,m-i);
    // }
    ll answer = k * fast_pow(n - k + 1, mod - 2) % mod;
    cout << answer << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
// #ifndef ONLINE_JUDGE
//     freopen("test.in", "r", stdin);
//     freopen("test.out", "w", stdout);
// #endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 25-8-1.
//
