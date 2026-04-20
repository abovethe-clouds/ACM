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
    int t,h,u;
    cin>>t>>h>>u;
    int ans=0;
    ans+=4*min(t,u);
    {
        int x=min(t,u);
        t-=x;
        u-=x;
    }
    ans+=5*min(t,h);
    {
        int x=min(t,h);
        t-=x;
        h-=x;
    }
    if (t>1)
        {ans+=t*3-(t-1);t=0;}

    ans+=3*(h+u+t);
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
// Created by Administrator on 2026/4/14.
//