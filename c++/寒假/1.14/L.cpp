#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int N = 1e5, M = N * 2, mod = 1e9 + 7, inf = INT_MIN, P = 131;
void solve()
{
    vector<pii> a[1001];
    memset(a,0,sizeof(a));
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int s,f,q;
        cin>>s>>f>>q;
        a[s].push_back(make_pair(f,q));
        a[f].push_back(make_pair(s,q));
    }
    priority_queue<pair<int,int>> q;
    int dis[1001];
    bool v[1001];
    memset(dis,inf,sizeof(dis));
    memset(v, 0, sizeof(v));
    dis[1]=INT_MAX;
    q.push(make_pair(dis[1],1));
    while (!q.empty())
    {
        int x=q.top().second;
        q.pop();
        if(v[x])
            continue;
        v[x]=1;
        for(auto heihei: a[x])
        {
            int w=heihei.second;//边权
            int y=heihei.first;//路径点
            if(dis[y]==0)
            {
				int min_weight = min(dis[x], w);  // 更新最小边权
                if (min_weight > dis[y]) 
                {  
                    dis[y] = min_weight;
                    q.push(make_pair(dis[y], y));
                }
            }
        }
    }
    
    cout<<dis[n]<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout<<"Scenario #"<<i<<":"<<endl;
        solve();
    }
    return 0;
}  