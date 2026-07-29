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
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (n&1)
    {
        cout<<"NO"<<endl;
        return;
    }
    int minn=inf;
    for (int i = 0; i < n; i+=2)
    {
        minn = min(minn, v[i]);
    }
    int maxx=-inf;
    for (int i =1; i<n; i+=2)
    {
        maxx = max(maxx, v[i]);
    }
    if (minn>maxx+1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
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
// Created by Administrator on 2026/7/26.
//