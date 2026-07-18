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
const int mod = 998244353, inf = 0x3f3f3f3f, P = 131;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        a[i]=s[i]-'0';
    int ans=0;
    vector<vector<int>> dp(n+1,vector<int>(3,0));
    dp[0][a[0]%3]=1;
    ans+=(a[0]%3==0&&a[0]%2==0);
    for(int i=1;i<n;i++)
    {
        if (a[i]%2==0)
        {
            if (a[i]%3==0)
                ans+=dp[i-1][0]+1,dp[i][0]=dp[i-1][0]+dp[i-1][0]+1,dp[i][1]=dp[i-1][1]*2,dp[i][2]=dp[i-1][2]*2;
            else if (a[i]%3==1)
                ans+=dp[i-1][2],dp[i][0]=dp[i-1][2]+dp[i-1][0],dp[i][1]=dp[i-1][0]+dp[i-1][1]+1,dp[i][2]=dp[i-1][2]+dp[i-1][1];
            else
                ans+=dp[i-1][1],dp[i][0]=dp[i-1][0]+dp[i-1][1],dp[i][1]=dp[i-1][1]+dp[i-1][2],dp[i][2]=dp[i-1][0]+dp[i-1][2]+1;
            dp[i][0]%=mod,dp[i][1]%=mod,dp[i][2]%=mod;
            ans%=mod;
        }
        else
        {
            if (a[i]%3==0)
                dp[i][0]=dp[i-1][0]+dp[i-1][0]+1,dp[i][1]=dp[i-1][1]*2,dp[i][2]=dp[i-1][2]*2;
            else if (a[i]%3==1)
                dp[i][0]=dp[i-1][2]+dp[i-1][0],dp[i][1]=dp[i-1][0]+dp[i-1][1]+1,dp[i][2]=dp[i-1][2]+dp[i-1][1];
            else
                dp[i][0]=dp[i-1][0]+dp[i-1][1],dp[i][1]=dp[i-1][1]+dp[i-1][2],dp[i][2]=dp[i-1][0]+dp[i-1][2]+1;
            dp[i][0]%=mod,dp[i][1]%=mod,dp[i][2]%=mod;
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
