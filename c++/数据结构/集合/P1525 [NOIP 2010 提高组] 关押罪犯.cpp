#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn=100000;
int fa[maxn*2];
struct stu
{
    int x,y,z;
}tree[maxn];
bool cmp(stu x,stu y)
{
    return x.z>y.z;
}
int find(int x)//查
{
    if(fa[x]==x)
        return x;
    else
        return fa[x]=find(fa[x]);
}
void add(int x,int y)//加
{
    fa[find(y)]=find(x);
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>tree[i].x>>tree[i].y>>tree[i].z;
    }
    for (int i = 0; i < n*2+2; i++)
    {
        fa[i]=i;
    }
    sort(tree,tree+m,cmp);
    for(int i=0;i<m;i++)
    {
        if(find(tree[i].x)==find(tree[i].y))
        {
            cout<<tree[i].z;
            return;
        }
        add(tree[i].x+n,tree[i].y);
        add(tree[i].y+n,tree[i].x);
    }
    cout<<0;
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