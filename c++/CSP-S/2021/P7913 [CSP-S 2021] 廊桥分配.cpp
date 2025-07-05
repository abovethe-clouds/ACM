#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn=1e5+5;
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
int k,m1,m2,resin[maxn],resout[maxn];
pii in[maxn],out[maxn];
void sol(pii* x,int n,int* res)
{
    priority_queue<int,vector<int>,greater<int>> q;
    priority_queue<pii,vector<pii>,greater<pii>> p;
    for (int i = 1; i <= k; i++)
    {
        q.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        while (!p.empty()&&x[i].first>p.top().first)
        {
            q.push(p.top().second);
            p.pop();
        }
        if(q.empty())
            continue;
        p.push(make_pair(x[i].second,q.top()));
        res[q.top()]++;
        q.pop();
    }
    for (int i = 0; i < k+1; i++)
    {
        res[i]=res[i]+res[i-1];
    }
    return;
}
void solve()
{
    cin>>k>>m1>>m2;
    for (int i = 1; i <= m1; i++)
        cin>>in[i].first>>in[i].second;
    for (int i = 1; i <= m2; i++)
        cin>>out[i].first>>out[i].second;
    sort(in+1,in+m1+1);
    sort(out+1,out+m2+1);
    sol(in,m1,resin);
    sol(out,m2,resout);
    int maxx=0;
    for (int i = 0; i <= k; i++)
    {
        maxx=max(maxx,resin[i]+resout[k-i]);
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