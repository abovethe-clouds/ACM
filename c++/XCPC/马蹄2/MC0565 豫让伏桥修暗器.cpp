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

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> x(n);
    vector<pii> y(m);
    for(int i=0;i<n;i++)
        cin>>x[i];
    for(int i=0;i<m;i++)
        cin>>y[i].first>>y[i].second;
    sort(y.begin(),y.end());
    int ans=0,j=n-1;
    set<int>st;
    for(int i=m-1;i>=0;i++)
    {
        int t=y[i].first,z=y[i].second;
        while (j>=0&&j+1>=t)
        {
            st.insert(x[j]);
            j--;
        }
        auto it=st.upper_bound(z);
        if(it!=st.begin())
        {
            --it;
            ans+=*it;
            st.erase(it);
        }
    }
    cout<<ans<<endl;

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
    cin>>t;
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2026/4/26.
//