#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 1e7 + 5;

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
bool prime[maxn] = {};
vector<int> is_prime;
ll phi[maxn];
ll sum[maxn] = {};
void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!prime[i])
        {
            is_prime.push_back(i);
            phi[i] = i - 1;
        }
        for (auto p : is_prime)
        {
            ll k = 1LL * p * i;
            if (k > n)
                break;
            prime[k] = 1;
            if (i % p == 0)
            {
                phi[k] = phi[i] * p;
                break;
            }
            else
            {
                phi[k] = phi[i] * (p - 1);
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i < n; i++)
        ans += phi[i];
    cout << ans * 2 + 1 << "\n";
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