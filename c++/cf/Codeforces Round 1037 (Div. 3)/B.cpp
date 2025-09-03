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
    const int n=read(),k=read();
    int a[n+1];
    for(int i=1;i<=n;i++)
        a[i]=read();
    int sum[n+1]={};
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    int dp[n+1]={};
    for(int i=k;i<=n;i++)
    {
        dp[i]=dp[i-1];
        if (sum[i]-sum[i-k]==0)
        {
            if (i>k)
                dp[i]=max(dp[i],dp[i-k-1]+1);
            else
                dp[i]=max(dp[i],1ll);
        }
    }
    cout<<dp[n]<<endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = read();
    //cin >> t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2025/9/2.
//