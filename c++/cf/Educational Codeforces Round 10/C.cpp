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
    const int n=read(), m=read();
    int a[n+1], pos[n+1];
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        pos[a[i]] = i;
    }
    int z[n+1];
    for (int i = 0; i <= n; i++)
        z[i] = inf;
    for (int i = 1; i <= m; i++)
    {
        int x = read(), y = read();
        int posx = pos[x], posy = pos[y];
        if (posx > posy)
            swap(posx, posy);
        z[posx]=min(z[posx], posy);
    }
    ll ans = 0;
    int r = n + 1;
    for (int l = n; l >= 1; l--)
    {
        r = min(r, z[l]);
        ans += r - l;
    }

    cout<<ans<<endl;

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
