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
string s;
int dp[1005][1005];
int dfs(int l,int r)
{
    if (l==r)
        return 0;
    if (dp[l][r]!=-1)
        return dp[l][r];
    if (l+1==r)
    {
        if (s[l]==s[r])
        {
            dp[l][r] = 0;
            return dp[l][r];
        }
        else
        {
            dp[l][r]=1;
            return dp[l][r];
        }
    }
    int ans = 0;
    if (s[l]==s[r])
        ans+=dfs(l+1,r-1);
    else
    {
        ans+=min(dfs(l,r-1),dfs(l+1,r))+1;
    }
    return dp[l][r] = ans;


}
void solve()
{
    memset(dp,-1,sizeof(dp));
    cin >> s;
    cout<<dfs(0,s.size()-1);
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
