#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=1e5+5;
vector<int> mp[maxn];
int n,m,end1[maxn];
bool e[maxn];
void dfs(int x,int d)
{
    if(e[x])
        return;
    end1[x]=d;
    e[x]=1;
    for (auto i:mp[x])
    {
        dfs(i,d);
    }
    
}
void solve()
{
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        mp[b].push_back(a);
    }
    for(int i=n;i>0;i--) dfs(i,i);
    for (int i = 1; i <= n; i++)
    {
        cout<<end1[i]<<" ";
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