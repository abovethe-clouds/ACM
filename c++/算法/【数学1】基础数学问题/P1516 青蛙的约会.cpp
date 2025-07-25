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
#define int ll
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
int exgcd(int a, int b, int &x, int &y) // 扩展欧几里得算法
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int temp = y;
    y = x - (a / b) * y;
    x = temp;
    return r;
}
int oula(int x)
{
    int ans = x;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
            {
                x /= i;
            }
            ans = ans / i * (i - 1);
        }
    }
    if (x > 1)
        ans = ans / x * (x - 1);
    return ans;
}
void solve()
{
    int x, y, m, n, l;
    cin >> x >> y >> m >> n >> l;
    int a = m - n, b = l, c = y - x;
    int x1, y1;
    int gcd = exgcd(a, b, x1, y1);
    if(c%gcd)
    {
        cout << "Impossible";
        return;
    }
    a /= gcd;
    b /= gcd;
    c /= gcd;
    //(ax+by=1)
    int u = x1 % b;
    if(u<0)
        u += b;
    int k = (u * (c % b)) % b;
    if(k<0)
        k += b;
    cout << k;
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
    // cin >> t;
    while (t--)
        solve();

    return 0;
}