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
const int mod = 1e9 + 7, inf = LONG_LONG_MAX, P = 131;

void solve()
{
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for (int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    vector<int> dp(n+1,inf);
    dp[0]=0;
    for (int i=1;i<=n;i++)
    {
        auto it=upper_bound(dp.begin(), dp.end(),arr[i])-dp.begin();
        it--;
        dp[it+1]=min(dp[it+1],dp[it]+arr[i]);
    }
    int cnt=0;
    for (int i=1;i<=n;i++)
    {
        if (dp[i]==inf)
            break;
        cnt++;
    }
    cout<<cnt<<endl;
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
// Created by Administrator on 2026/7/28.
//