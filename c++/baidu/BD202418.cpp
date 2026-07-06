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
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,pian=1e9+5;

void solve()
{
    int n;
    cin>>n;
    int now=pian;
    vector<pii> a;
    for(int i=0;i<n;i++)
    {
        int l;
        char c;
        cin>>l>>c;
        if (c=='R')
        {
            a.push_back({now,1});
            now=now+l-1;
            a.push_back({now+1,-1});
        }
        else
        {
            a.push_back({now+1,-1});
            now=now-l+1;
            a.push_back({now,1});
        }
    }
    sort(a.begin(),a.end());
    sort(a.begin(),a.end());
    vector<pii> b;
    for(auto [x,v]:a)
    {
        if(!b.empty() && b.back().first==x)
        {
            b.back().second+=v;
        }
        else
        {
            b.push_back({x,v});
        }
    }
    vector<pii> mp;
    int cur=0;
    for(auto [x,v]:b)
    {
        cur=((cur+v)%4+4)%4;
        mp.push_back({x,cur});
    }
    long long ans=0;
    for(int i=0;i+1<mp.size();i++)
    {
        if(mp[i].second==1)
        {
            ans+=1LL*(mp[i+1].first-mp[i].first);
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
    while (t--)
        solve();
    return 0;
}
