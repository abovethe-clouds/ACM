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
struct num_500
{
    int a[600] = {};
};
num_500 operator*(num_500 a, num_500 b)
{
    num_500 n;
    for (int i = 1; i <= 500; i++)
    {
        for (int j = 1; j <= 500; j++)
        {
            if (i + j - 1 > 500)
                break;
            n.a[j + i - 1] += a.a[i] * b.a[j];
        }
    }
    int ans = 0;
    for (int i = 0; i <= 500; i++)
    {
        n.a[i] += ans;
        ans = 0;
        if (n.a[i] >= 0)
        {
            ans = n.a[i] / 10;
            n.a[i] %= 10;
        }
    }
    return n;
}
num_500 fast_pow(num_500 a, int b)
{
    num_500 ans;
    ans.a[1] = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = a * ans;
        }
        a = a * a;
        b /= 2;
    }
    return ans;
}

void solve()
{
    int p;
    cin >> p;
    cout << int(p * log10(2) + 1);
    num_500 n;
    n.a[1] = 2;
    num_500 ans = fast_pow(n, p);
    ans.a[1]--;
    for (int i = 500; i >= 1; i--)
    {
        if (i % 50 == 0)
            cout << endl;
        cout << ans.a[i];
    }
    return;
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