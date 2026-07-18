#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int long long
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
int sum(vector<int> v)
{
    int s = 0;
    for (int x : v)
        s += x;
    return s;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        {cin >> b[i];b[i]--;}
    sort(b.begin(), b.end());
    vector<int> c(n);
    int pre = 0;
    for (int i = 0; i < n; i++)
    {
        pre += a[i];
        c[i] = -2 * pre;
    }
    int maxx=0;
    for (int i=0;i<m;i++)
    {
        maxx=max(maxx,c[b[i]]);
    }
    cout<<maxx+sum(a)<<endl;
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
    cin >> t;
    while (t--)
        solve();
    return 0;
}

//
// Created by Administrator on 2026/7/14.
//
