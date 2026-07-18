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
    int n=read();
    vector<int> v(n+1);
    for (int i=1;i<=n;i++)
        v[i]=read();
    map<ll,vector<int>> mp;
    mp[0].push_back(0);
    ll sum=0;
    vector<pii> seg;
    for (int i=1;i<=n;i++)
    {
        sum+=v[i];
        if (mp.count(sum))
        {
            seg.push_back({mp[sum].back()+1,i});
        }
        mp[sum].push_back(i);
    }
    sort(seg.begin(),seg.end(),[](pii a,pii b){return a.sec<b.sec;});
    int ans=0,last=0;
    for (auto x:seg)
    {
        if (x.fir>last)
        {
            ans++;
            last=x.sec;
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
    t=read();
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2026/2/26.
//