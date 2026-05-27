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
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> a(n+2),dp(n+2,0),sum(n+2,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1];
        for(int j=1;j<=i;j++)
        {
            if (sum[i]-sum[j-1]<=r&&sum[i]-sum[j-1]>=l)
            {
                dp[i]=max(dp[i],dp[j-1]+1);
            }
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
// Created by Administrator on 2026/5/7.
//