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
const int maxn = 2e3 + 5;
int n, m;
vector<pii> mp[maxn];
void SPFA(int start)
{
    queue<int> q;
    int dis[n+1],cnt[n+1]={},vis[n+1]={};
    fill(dis, dis + n + 1, inf);
    dis[start] = 0;
    q.push(start);
    while (!q.empty())
    {
        auto i = q.front();
        vis[i] = 0;//出队
        q.pop();
        for (auto ii : mp[i] )
        {
            if(dis[i]+ii.second<dis[ii.first])
            {
                cnt[ii.first]++;
                dis[ii.first] = dis[i] + ii.second;
                if (!vis[ii.first])
                {
                    q.push(ii.first);
                    vis[ii.first] = 1;
                }
            }
            if (cnt[ii.first] == n)
            {
                cout << "YES" << endl;
                return;
            }
        }   
    }
    cout << "NO" << endl;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        mp[i].clear();
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if(w>=0)
        {
            mp[u].push_back(make_pair(v, w));
            mp[v].push_back(make_pair(u, w));
        }
        else
            mp[u].push_back(make_pair(v, w));
    }
    SPFA(1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        //freopen("test.in", "r", stdin);
       // freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}