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
struct edge
{
    int e1,e2,x,y;
};
edge readEdge()
{
    edge p{};
    p.e1 = read(), p.e2 = read(), p.x = read(), p.y = read();
    if (p.e1>p.e2)
        swap(p.e1,p.e2);
    return p;
}
void solve()
{
    const int N=read();
    vector<int> dis(N+1,inf);
    vector<edge> e(N);
    vector<pii> mp[N+1];
    for (int i=1;i<N;i++)
    {
        e[i]=readEdge();
        mp[e[i].e1].push_back({e[i].e2,i});
        mp[e[i].e2].push_back({e[i].e1,i});
    }
    bool vis[N+1]={};
    int l=-1,r=1;
    dis[1]=0;
    vis[1]=true;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int begin=q.front();
        q.pop();
        for (int i=0;i<mp[begin].size();i++)
        {
            int to=mp[begin][i].first;
            if (vis[to])
                continue;
            edge ed=e[mp[begin][i].second];
            auto [e1,e2,x,y]=ed;
            if (begin<to)
            {
                if (x>y)
                {
                    dis[e2]=l;
                    l--;
                    vis[e2]=true;
                }
                else
                {
                    dis[e2]=r;
                    r++;
                    vis[e2]=true;
                }
            }
            else
            {
                if (x>y)
                {
                    dis[e1]=r;
                    r++;
                    vis[e1]=true;
                }
                else
                {
                    dis[e1]=l;
                    l--;
                    vis[e1]=true;
                }
            }
            q.push(to);
        }
    }
    int min=*min_element(dis.begin()+1,dis.end());
    min=abs(min)+1;
    for (int i=1;i<=N;i++)
        cout<<dis[i]+min<<" ";
    cout<<endl;


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
