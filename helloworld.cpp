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
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=1e5+5;
vector<int> mp[maxn];
vector<int> cnt(maxn,0),sp;
int fa[maxn][21],hig[maxn];
vector<int> sum(maxn,0);
void dfs(int x,int f)
{
    fa[x][0]=f;
    hig[x]=hig[f]+1;

    sum[x]=sum[f]+cnt[x];

    for (int i = 1; i < 21; i++)
    {
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }

    for (auto i : mp[x])
    {
        if(i!=f)
            dfs(i,x);
    }
}
int LCA(int x,int y)
{
    if(hig[x]<hig[y])
        swap(x,y);
    for (int i = 20; i >= 0; i--)
    {
        if(hig[x]-(1<<i)>=hig[y]) x=fa[x][i];
    }
    if(x==y)
        return x;
    for (int i = 20; i >= 0; i--)
    {
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    }
    return fa[x][0];

}
void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        mp[x].emplace_back(y);
        mp[y].emplace_back(x);
        cnt[x]++;
        cnt[y]++;
    }
    dfs(1,0);
    while(m--)
    {
        int u,v;
        cin>>u>>v;

        int lca=LCA(u,v);

        long long ans = sum[u] + sum[v] - 2*sum[lca] + cnt[lca];

        cout<<ans<<endl;
    }

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
