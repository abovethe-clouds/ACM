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
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn=500005;
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
vector<pii> mp[maxn];
void input()
{
    n= read();
    for (int i = 1; i < n; i++)
    {
        int u=read(),v=read(),w=read();
        mp[u].push_back({v,w});
        mp[v].push_back({u,w});
    }
}

void solve_dfs()//树的直径用2次dfs求解
{
    input();
    int strat=1;
    vector<int> dis(maxn,0);
    function<void(int,int)> dfs=[&](int x,int fa)
    {
        for (auto &[to,w]:mp[x])
        {
            if (to==fa)
                continue;
            dis[to]=dis[x]+w;
            if (dis[to]>dis[strat])
            {
                strat=to;
            }
            dfs(to,x);
        }
    };
    dfs(1,0);
    fill(dis.begin(),dis.end(),0);
    int end=strat;
    dfs(strat,0);
    cout<<dis[strat]<<endl;
}
void solve_tree_dp()
{
    input();
    vector<int> ans(maxn,0),dis(maxn,0);//ans[i]表示以i为根的子树的最大距离，dis[i]表示以i为根往下的最大距离
    int strat=1;
    function<void(int,int)> dfs=[&](int x,int fa)
    {
        for (auto &[to,w]:mp[x])
        {
            if (to==fa)
                continue;
            dfs(to,x);
            ans[x]=max(ans[x],dis[x]+dis[to]+w);
            dis[x]=max(dis[x],dis[to]+w);
            if (ans[x]>ans[strat])
            {
                strat=x;
            }
        }
    };
    dfs(1,0);
    cout<<ans[strat]<<endl;
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
    //t = read();
    while (t--)
        solve_tree_dp();
    return 0;
}
