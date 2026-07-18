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
    int n,m;
    cin>>n>>m;
    vector<int> dp(n+1,0);
    vector<pii> cost(m);
    for (auto &[a,b]:cost) cin>>a>>b;
    for (int i=0;i<m;i++)
    {
        for (int j=n;j>=cost[i].first;j--)
        {
            dp[j]=max(dp[j],dp[j-cost[i].first]+cost[i].second*cost[i].first);
        }
    }
    cout<<dp[n]<<endl;
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
    //cin >> t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2026/7/22.
//