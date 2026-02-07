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
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=2e5+5;
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
vector<int> mp[maxn],v(maxn);
int dp[maxn][2];
int n;
void clear()
{
    for (int i=1;i<=n;i++)
    {
        mp[i].clear();
        dp[i][0]=0;
        dp[i][1]=0;
    }
}
void dfs(int x,int fa)
{
    dp[x][0]=max(v[x],v[x]-dp[fa][1]);
    dp[x][1]=min(v[x],v[x]-dp[fa][0]);
    for (auto to:mp[x])
    {
        if (to == fa) continue;
        dfs(to,x);
    }
}

void solve()
{
    n=read();
    clear();
    for (int i=1;i<=n;i++)
    {
        v[i]=read();
    }
    for (int i=1;i<n;i++)
    {
        int a=read(),b=read();
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    dp[1][0]=dp[1][1]=v[1];
    for (auto to:mp[1])
    {
        dfs(to,1);
    }
    for (int i=1;i<=n;i++)
    {
        cout<<dp[i][0]<<" ";;
    }
    cout<<endl;
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
    t = read();
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2026/2/5.
//