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
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<int> a(x),b(y),c,d,e;
    for(int i=0;i<x;i++)
        cin>>a[i];
    for(int i=0;i<y;i++)
        cin>>b[i];
    int i=0,j=0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            c.push_back(a[i]);
            ++i;
            ++j;
        } else if (a[i] < b[j]) {
            d.push_back(a[i]);
            ++i;
        } else {
            e.push_back(b[j]);
            ++j;
        }
    }
    d.insert(d.end(), a.begin() + i, a.end());
    e.insert(e.end(), b.begin() + j, b.end());
    sort(d.begin(), d.end(), greater<int>());
    sort(e.begin(), e.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());
    vector<int> ans;
    int dn = min((int)d.size(), n);
    ans.insert(ans.end(), d.begin(), d.begin() + dn);
    int em = min((int)e.size(), m);
    ans.insert(ans.end(), e.begin(), e.begin() + em);
    ans.insert(ans.end(), c.begin(), c.end());
    sort(ans.begin(), ans.end(), greater<int>());
    int take = min((int)ans.size(), n + m - 1);
    ll sum = 0;
    for (int i = 0; i < take; i++)
        sum += ans[i];
    cout << sum << endl;
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
}//
// Created by Administrator on 2026/8/7.
//