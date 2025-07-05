#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
int N,M,S;
int fa[500005][21],hig[500005];
vector<int> mp[500005];
void dfs(int x,int f)
{
    fa[x][0]=f;
    hig[x]=hig[f]+1;
    for (int i = 1; i < 20; i++)
    {
        fa[x][i]=fa[fa[x][i-1]][i-1];
    }
    
    for (auto  i : mp[x])
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
    cin>>N>>M>>S;
    for (int i = 0; i < N-1; i++)
    {
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    hig[0]=-1;
    dfs(S,0);
    for (int i = 0; i < M; i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<LCA(a,b)<<endl;
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    while(t--)
        solve();

    return 0;
}