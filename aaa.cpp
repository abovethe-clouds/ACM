#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=2e5+10;
#define int ll
struct  point
{
    ll sum,lazy=0,maxx;
    point operator+ (const point q)const
    {
        point n;
        n.sum=q.sum+sum;
        n.lazy=0;
        n.maxx=max(maxx,q.maxx);
        return n;
    }
};
point tree[maxn*4];
int v[maxn];
int ls(int x)
{
    return x*2;
}
int rs(int x)
{
    return x*2+1;
}
void push_up(int x)
{
    tree[x]=tree[ls(x)]+tree[rs(x)];
    return;
}
void lazy_down(int root ,int l,int r,int add)
{
    tree[root].sum+=add*(r-l+1);
    tree[root].lazy+=add;
    tree[root].maxx+=add;
    return;
}
void push_down(int root,int l,int r)
{
    if(l==r) return;
    if(tree[root].lazy==0)
    {
        return;
    }
    int add=tree[root].lazy;
    int mid=(l+r)/2;
    lazy_down(ls(root),l,mid,add);
    lazy_down(rs(root),mid+1,r,add);

    tree[root].lazy=0;
}
void add(int root,int L,int R,int l,int r,int ad)
{
    if(L<=l && r<=R)
    {
        tree[root].sum+=(r-l+1)*ad;
        tree[root].maxx+=ad;
        tree[root].lazy+=ad;
        return;
    }
    push_down(root,l,r);
    int mid=(l+r)/2;
    if(L<=mid)
    {
        add(ls(root),L,R,l,mid,ad);
    }

    if(R>mid)
    {
        add(rs(root),L,R,mid+1,r,ad);
    }

    push_up(root);
}
point find(int root,int L,int R,int l,int r)
{
    if(L<=l && r<=R)
    {
        return tree[root];
    }
    push_down(root,l,r);
    int mid=(l+r)/2;
    if(R<=mid)
    {
        return find(ls(root),L,R,l,mid);
    }
    if(L>mid)
    {
        return find(rs(root),L,R,mid+1,r);
    }

    return find(ls(root),L,R,l,mid)
         + find(rs(root),L,R,mid+1,r);
}
void built(int root,int l,int r)
{
    if(l==r)
    {
        tree[root].sum=v[l];
        tree[root].lazy=0;
        tree[root].maxx=v[l];
        return;
    }
    int mid=(l+r)/2;
    built(ls(root),l,mid);
    built(rs(root),mid+1,r);
    push_up(root);
    return;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i = 1; i < n+1; i++)
    {
        cin>>v[i];
    }
    built(1,1,n);
    while(m--)
    {
        string s;
        int l,r;
        cin>>s>>l>>r;
        if (s=="CHECK")
        {
            cout<<((find(1,l,r,1,n).maxx>=440)?"YES":"NO")<<endl;
        }
        else
        {
            int x=find(1,l,r,1,n).sum;
            x/=(r-l+1);
            if (x>=360)
                add(1,l,r,1,n,10);
            else if (x>=100)
                add(1,l,r,1,n,15);
            else
                add(1,l,r,1,n,20);
        }
    }

}
signed main()
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