#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
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
int n;
int dp[1005][1005][2],a[1005];
int dfs(int l,int r)
{
    if (l+1==r)
    {
        if (a[r]>a[l])
        {
            dp[l][r][0] = 1;
            dp[l][r][1] = 1;
        }
        return (dp[l][r][0]+dp[l][r][1])%mod;
    }
    if (dp[l][r][0]!=-1&&dp[l][r][1]!=-1)
        return (dp[l][r][0]+dp[l][r][1])%mod;
    if (a[l]<a[r])
        dp[l][r][0] = (dp[l][r][0]+dp[l+1][r][1])%mod;
    if ((
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    n=read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    cout<<dfs(1,n);
}

int main()
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
}
