#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e4, inf = 0x3f3f3f3f, P = 131;

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
int fast_pow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans *= a;
            ans %= mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

void solve()
{
    int a, b;
    int sum[mod + 5] = {};
    cin >> a >> b;
    for (int i = 1; i <= min(mod, a); i++)
    {
        sum[i] = (sum[i - 1] + fast_pow(i, b)) % mod;
    }
    cout << ((a / mod) * sum[mod] + sum[a % mod]) % mod << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}