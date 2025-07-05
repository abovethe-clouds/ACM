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
const int dx[8] = {-1,0,1,0,-1,-1,1,1}, dy[8] = {0,1,0,-1,-1,1,-1,1},maxn=1e5+5;
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
vector<int> mp[maxn];
bool j[maxn]={};
int n,d,ans=0;
void dfs(int n,int step)
{
    j[n]=1;
    if(step==d)
        return;
    for(auto i : mp[n])
    {
        if(!j[i])
        {
            ans++;
            
            dfs(i,step+1);
        }
    }
}
void solve()
{
    cin>>n>>d;
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    dfs(1,0);
    cout<<ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        freopen("test.in", "r", stdin);
        //freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    while(t--)
        solve();

    return 0;
}