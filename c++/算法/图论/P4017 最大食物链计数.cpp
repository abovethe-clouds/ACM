#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 80112002, inf = 0x3f3f3f3f, P = 131;
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
void solve()
{
    int n,m;
    cin>>n>>m;
    int ludu[n+1]={},chudu[n+1]={};
    vector<int> mp[n+1];
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        chudu[a]++;
        ludu[b]++;
        mp[a].push_back(b);
    }
    queue<int> p;
    int f[n+1]={};
    for(int i=1;i<=n;i++)
    {
        if(ludu[i]==0)
        {
            f[i]=1;
            p.push(i);
        }    
    }
    while (!p.empty())
    {
        int h=p.front();
        p.pop();
        for(auto i:mp[h])
        {
            ludu[i]--;
            f[i]=(f[i]+f[h])%mod;
            if(ludu[i]==0)
                p.push(i);
        }
    }
    int sum=0;
    for (int i = 1; i < n+1; i++)
    {
        if(chudu[i]==0)
            sum=(sum+f[i])%mod;
    }
    cout<<sum;
    
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
    while(t --)
        solve();

    return 0;
}