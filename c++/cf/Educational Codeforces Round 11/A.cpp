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
    const int n=read();
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = read();
    int ans = 0;
    vector<int> pos;
    for (int i = 0; i < n-1; i++)
    {
        pos.push_back(v[i]);
        if (__gcd(v[i], v[i+1]) != 1)
        {
            ans++;pos.push_back(1);
        }

    }
    cout << ans << endl;
    pos.push_back(v[n-1]);
    for (auto i : pos)
        cout << i << " ";
}

int main()
{

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
