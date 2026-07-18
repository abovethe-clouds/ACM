#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;

void solve()
{
    int x, y, n, m;
    cin >> x >> y >> n >> m;
    vector<int> a(n),b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int x_min=inf, y_min=inf, x_max=-inf, y_max=-inf;
    a.push_back(0),b.push_back(0);
    for (int i = 0; i <= n; i++)
    {
        x_min = min(x_min, a[i]);
        x_max = max(x_max, a[i]);
    }
    for (int i = 0; i <= m; i++)
    {
        y_min = min(y_min, b[i]);
        y_max = max(y_max, b[i]);
    }
    cout<<max(max((x+x_max)*(y+y_max),(x+x_max)*(y+y_min)),max((x+x_min)*(y+y_max),(x+x_min)*(y+y_min)))<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 2026/7/21.
//
