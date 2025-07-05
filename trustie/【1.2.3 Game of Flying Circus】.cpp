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
double L = 300;

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
double v1, v2, t;
bool judeg1()
{
    if (2.0 * v1 * v1 - v2 * v2 < 0)
        return 0;
    if ((v1 / v2) < (1 / sqrt(2)))
        return 0;
    double t1 = (L * v2 - L * sqrt(2 * v1 * v1 - v2 * v2)) / (v2 * v2 - v1 * v1);
    double x = v2 * t1 - L;
    if (x < 0 || x >= L)
        return 0;
    if (((2 * L + x) / v1) <= t)
        return 1;
    if ((((2 * L - x) / v2)) >= (((2 * L + x) / v1) - t))
        return 1;
    return 0;
}
bool judge2()
{
    if ((v1 / v2) < (1.0 / sqrt(8)))
        return 0;
    double t1 = (3 * L * v2 - (L * sqrt(8 * v1 * v1 - v2 * v2))) / (v2 * v2 - v1 * v1);
    double d = t1 * v2 - 2 * L;
    if (d < 0 || d > L)
        return 0;
    if (((d + L + L + L + L) / v1) <= t)
        return 1;
    if ((sqrt(d * d + L * L) + 2 * L / v1) <= (L - d) / v2 + t)
        return 1;
    else
        return 0;
}
void solve()
{

    cin >> t >> v1 >> v2;
    if (v1 >= v2)
    {
        cout << "Yes" << endl;
        return;
    }
    if (v1 == 0)
    {
        cout << "No" << endl;
        return;
    }
    if (judeg1())
    {
        cout << "Yes" << endl;
        return;
    }
    if (judge2())
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
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
    cin >> t;
    while (t--)
        solve();

    return 0;
}