#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131 ,maxn=2e5+5;
vector <int> v;int a[maxn];
struct hjt
{
    int l,r,sum;
}tree[40*maxn];
int cnt,root[maxn];
int getid(int x)//离散化
{
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
void insert(int l,int r,int pre,int &now,int k)
{
    tree[++cnt]=tree[pre];
    now=cnt;
    tree[now].sum++;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(k<=mid) insert(l,mid,tree[pre].l,tree[now].l,k);
    else insert(mid+1,r,tree[pre].r,tree[now].r,k);
    return;
}
int find(int l,int r,int L,int R,int k)
{
    if(l==r) return l;
    int m=(l+r)>>1;
    int tem=tree[tree[R].l].sum-tree[tree[L].l].sum;
    if(k<=tem) return find(l,m,tree[L].l,tree[R].l,k);
    else return find(m+1,r,tree[L].r,tree[R].r,k-tem);
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        int o;
        cin>>o;
        v.push_back(o);//v离散化后的数字
        a[i]=o;
        
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for (int i = 1; i <= n; i++)
    {
        insert(1,n,root[i-1],root[i],getid(a[i]));
    }
    while(m--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        cout<<v[find(1,n,root[l-1],root[r],k)-1]<<endl;
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