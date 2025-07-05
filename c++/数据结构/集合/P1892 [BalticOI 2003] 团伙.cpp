#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn= 1e4+5;
int fa[maxn];
int find(int xyy)
{
    if(xyy==fa[xyy])
        return xyy;
    else
        return fa[xyy]=find(fa[xyy]);
}
void add(int x,int y)
{
    fa[find(x)]=find(fa[y]);
    return;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n*2;i++)
    {
        fa[i]=i;
    }
    for (int i = 0; i < m; i++)
    {
        char c;
        int a,b;
        cin>>c>>a>>b;
        if(c=='E')//敌人
        {
            add(a+n,b);
            add(b+n,a);
        }
        if(c=='F')
        {
            add(a,b);
        }
    }
    int cnt=0;
    for (int i = 1; i <= n; i++)
    {
        if(fa[i]==i)
            cnt++;
    }
    cout<<cnt;
    
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
