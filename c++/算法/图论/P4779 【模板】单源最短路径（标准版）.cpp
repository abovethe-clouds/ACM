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
const int maxn=2e5;
int n,m,s;
vector<pii> mp[maxn];
int l[maxn];
bool vis[maxn];
void dij()
{
    fill(l,l+maxn,1e9);
    l[s]=0;
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push(make_pair(l[s],s));
    while (!q.empty())
    {
        pii x=q.top();
        q.pop();
        if(vis[x.second])
            continue;
        vis[x.second]=1;
        for (auto a: mp[x.second])
        {
            if(l[x.second]+a.first<l[a.second])
            {
                q.push(make_pair(x.first+a.first,a.second));
                l[a.second]=l[x.second]+a.first;
            }   
        }
        
    }
    
}
void solve()
{
    cin>>n>>m>>s;
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        mp[a].push_back(make_pair(c,b));
    }
    dij();
    for (int i = 1; i <= n; i++)
    {
        cout<<l[i]<<" ";
    }
    
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
}