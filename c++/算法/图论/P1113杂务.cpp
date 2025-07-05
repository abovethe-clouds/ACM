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
    int n;
    cin>>n;
    int in[n+1]={},out[n+1]={},v[n+1]={},sum[n+1]={};
    bool judge[n+1]={};
    vector<int> mp[n+1];
    for (int i = 0; i < n; i++)
    {
        int x, l;
        cin >> x >> v[x];
        while (true)
        {
            int p;
            cin >> p;
            if (p == 0) break;
            mp[p].push_back(x);
            in[x]++;
            out[p]++;
        }
    }
    queue<int> q;
    for (int i = 1; i < n+1; i++)
    {
        if(!in[i])
        {
            sum[i]=v[i];
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int t=q.front();
        q.pop();
        for(auto i : mp[t])
        {
            if(!judge[i])
            {
                sum[i]=sum[t]+v[i];
                judge[i]=1;
            }
            else
                sum[i]=max(sum[i],sum[t]+v[i]);
            in[i]--;
            if(!in[i])
                q.push(i);
        }
    }
    int maxx=-1;
    for (int i = 1; i < n+1; i++)
    {
        if(!out[i])
            maxx=max(sum[i],maxx);
    }
    cout<<maxx;
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