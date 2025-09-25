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
    const int N = read();
    vector<int> a(N),b(N);
    for(int i=0;i<N;i++)
        a[i]=read();
    for(int i=0;i<N;i++)
        b[i]=read();
    int dp[N][2]={};
    dp[0][0]=1,dp[0][1]=1;
    for(int i=1;i<N;i++)
    {
        if (a[i-1]<=a[i]&&b[i-1]<=b[i])
            dp[i][0]=(dp[i-1][0]+dp[i][0])%mod;
        if (b[i-1] <= a[i] && a[i-1] <= b[i])
            dp[i][0]=(dp[i-1][1]+dp[i][0])%mod;
        if (a[i-1]<=b[i]&&b[i-1]<=a[i])
            dp[i][1]=(dp[i-1][1]+dp[i][1])%mod;
        if (b[i-1] <= b[i] && a[i-1] <= a[i])
            dp[i][1]=(dp[i-1][1]+dp[i][1])%mod;
    }
    cout<<(dp[N-1][0]+dp[N-1][1])%mod<<endl;
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
    t=read();
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2025/9/16.
//