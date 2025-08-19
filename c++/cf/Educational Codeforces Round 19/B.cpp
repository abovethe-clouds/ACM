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

void solve()
{
    const int n = read();
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = read();
    int odd = -inf, even = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2==0)
        {

            odd = max(odd, odd + v[i]);
            even = max(even, even + v[i]);
        } else
        {
            int even1=even;
            even = max(even, odd + v[i]);
            odd = max(odd, even1 + v[i]);
        }
    }
    cout << odd << endl;
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
}
