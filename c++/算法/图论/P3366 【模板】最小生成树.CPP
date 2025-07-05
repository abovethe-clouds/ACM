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
int n,m;
const int maxn=5e3+5;
struct edge
{
    int l,e1,e2;
    bool operator<(const edge & q)const
    {
        return l>q.l;
    }
};

priority_queue<edge> q;
int f[maxn];
int find(int x)
{
    if(f[x]==x)
        return x;
    return f[x]=find(f[x]);
}
void add(int x,int y)
{
    f[find(f[x])]=find(f[y]);
    return;
}
int cnt=0,sum=0;
void dij()
{
    while (cnt!=n-1&&!q.empty())
    {
        edge neww=q.top();
        q.pop();
        if(find(neww.e1)==find(neww.e2))
            continue;
        sum+=neww.l;
        cnt++;
        add(neww.e1,neww.e2);
    }
    

}
void solve()
{
    n=read(),m=read();
    for (int i = 0; i <= n; i++)
    {
        f[i]=i;
    }
    
    for (int i = 0; i < m; i++)
    {
        int a=read(),b=read(),c=read();
        edge pp;
        pp.e1=a,pp.e2=b,pp.l=c;
        q.push(pp);
    }
    dij();
    if(cnt==n-1)
        cout<<sum;
    else
        cout<<"orz";
    return;
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