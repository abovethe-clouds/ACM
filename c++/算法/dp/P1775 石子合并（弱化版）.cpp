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

int a[305];
int sum[305] = {};
int dp[305][305];
int dfs(int l,int r)
{
    if (l==r)
    {
        return 0;
    }
    if (dp[l][r]!=-1)
        return dp[l][r];
    int ans=INT_MAX;
    for (int i=l; i<r; i++)
    {
        ans=min(ans,dfs(l,i)+dfs(i+1,r)+sum[r]-sum[l-1]);
    }
    return dp[l][r]=ans;
}
void solve()
{
    const int N = read();
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; i++)
        a[i] = read();
    for (int i = 1; i <= N; i++)
        sum[i] = sum[i - 1] + a[i];
    cout<<dfs(1,N)<<endl;
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
