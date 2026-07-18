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
    vector<vector<int>> cost(n+1, vector<int>(n+1));
    for (int i = 1; i < n; i++)
    {
        for (int j=i+1; j<=n; j++)
            cin>>cost[i][j];
    }
    vector<int> dp(n+1,inf);
    dp[1]=0;
    for (int i=2;i<=n;i++)
    {
        for (int j=1;j<i;j++)
        {
            dp[i]=min(dp[j]+cost[j][i],dp[i]);
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