#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
vector<int> ans(1000005, 0);
void solve()
{
    int n,k,ans=0;
    cin>>n>>k;
    for (int i=0;i<32;i++)
    {
        int x=(1<<i);
        if (x*k<=n)
        {
            n-=x*k;
            ans+=k;
        }
        else
        {
            ans+=n/x;
            n=0;
            break;
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
// Created by Administrator on 2026/7/10.
//