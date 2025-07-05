#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn=2e5+5;
int fa[maxn];
int find(int x)
{
    if(x==fa[x])
        return x;
    else
        return fa[x]=find(fa[x]);
}
void add(int x,int y)
{
    fa[find(fa[x])]=find(y);
    return;
}
char fi(int x,int y)
{
    return ((find(x)==find(y))?'Y':'N');
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        fa[i]=i;
    }
    for (int i = 0; i < m; i++)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1)
            add(x,y);
        else
            cout<<fi(x,y)<<endl;
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