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
struct note
{
    char a,b;
    int time;
};
void solve()
{
    int n;
    cin>>n;
    vector<note> v(n+1);
    vector<int> dp(n+1, 0);
    for(int i=1;i<=n;i++)
        cin>>v[i].a>>v[i].b>>v[i].time;
    sort(v.begin()+1,v.end(),[](note a,note b)
    {
        return a.time<b.time;
    });
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if (v[i].a==v[i].b)
        {
            if (v[i].time-v[i-1].time<=1000)
                dp[i]=dp[i-1]+1;
            else
                dp[i]=1;
        }
        else
        {
            dp[i]=0;
        }
        ans=max(ans,dp[i]);

    }
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2026/5/2.
//