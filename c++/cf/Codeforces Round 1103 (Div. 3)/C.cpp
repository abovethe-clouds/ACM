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
const int mod = 1e9 + 7, inf = 0x66ccff66, P = 131;

void solve()
{
    int a,b,x;
    cin>>a>>b>>x;
    int ans=inf;
    for (int i=0;i<32;i++)
    {
        int _b=b;
        for (int j=0;j<32;j++)
        {
            ans=min(ans,abs(a-_b)+i+j);
            _b/=x;
        }
        a/=x;
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
// Created by Administrator on 2026/6/14.
//