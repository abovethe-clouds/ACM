#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=2e6+5;
#define int ll
struct  point
{
    ll sum,lazy=0,tag=0;bool use_tag=0;
    point operator+ (const point q)const
    {
        point n;
        n.sum=std::max(q.sum,sum);
        n.lazy=0;
        n.use_tag=0;
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
    tree[x].sum=max(tree[ls(x)].sum,tree[rs(x)].sum);
    return;
}
void lazy_down(int root ,int l,int r,int add)
{
    tree[root].sum+=add;
    tree[root].lazy+=add;
    return;
}
void tag_down(int root,int change)
{
    tree[root].sum=change;
    tree[root].lazy=0;
    tree[root].tag=change;
    tree[root].use_tag=1;
    return;
}
void push_down(int root,int l,int r)
{
    if(tree[root].use_tag)
    {
        tag_down(ls(root),tree[root].tag);
        tag_down(rs(root),tree[root].tag);
        tree[root].use_tag=0;
    }
    int add=tree[root].lazy;
    int mid=(l+r)/2;
    lazy_down(ls(root),l,mid,add);
    lazy_down(rs(root),mid+1,r,add);
    tree[root].lazy = 0;
    push_up(root);
    return;
    return;
}
void change(int root,int l,int r,int l_r,int r_r,int chang)
{
    if(l==l_r&&r==r_r)
    {
        tree[root].sum=chang;
        tree[root].tag=chang;
        tree[root].lazy=0;
        tree[root].use_tag=1;
        tree[ls(root)].lazy=0;
        tree[rs(root)].lazy=0;
        return;
    }
    push_down(root,l_r,r_r);
    int mid=(l_r+r_r)/2;
    if(r<=mid)
        change(ls(root),l,r,l_r,mid,chang);
    else if(l>mid)
        change(rs(root),l,r,mid+1,r_r,chang);
    else
    {
        change(ls(root),l,mid,l_r,mid,chang);
        change(rs(root),mid+1,r,mid+1,r_r,chang);
    }
    push_up(root);
}
void add(int root,int l,int r,int l_r,int r_r,int ad)
{
    if(l==l_r&&r==r_r)
    {
        tree[root].sum+=ad;
        tree[root].lazy+=ad;
        return;
    }
    push_down(root,l_r,r_r);
    int mid=(l_r+r_r)/2;
    if(r<=mid)
        add(ls(root),l,r,l_r,mid,ad);
    else if(l>mid)
        add(rs(root),l,r,mid+1,r_r,ad);
    else
    {
        add(ls(root),l,mid,l_r,mid,ad);
        add(rs(root),mid+1,r,mid+1,r_r,ad);
    }
    push_up(root);
}
int find(int root,int l,int r,int l_r,int r_r)
{
    if(l==l_r&&r==r_r)
    {
        return tree[root].sum;
    }
    push_down(root,l_r,r_r);
    int mid=(l_r+r_r)/2;
    if(r<=mid)
        return find(ls(root),l,r,l_r,mid);
    else if(l>mid)
        return find(rs(root),l,r,mid+1,r_r);
    else
    {
        return max(find(ls(root),l,mid,l_r,mid),find(rs(root),mid+1,r,mid+1,r_r));
    }
    push_up(root);
}
void built(int root,int l,int r)
{
    if(l==r)
    {
        tree[root].sum=v[l];
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
        int make;
        cin>>make;
        if(make==1)
        {
            ll l,r,ad;
            cin>>l>>r>>ad;
            change(1,l,r,1,n,ad);
        }
        else if(make==2)
        {
            ll l,r,ad;
            cin>>l>>r>>ad;
            add(1,l,r,1,n,ad);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<find(1,l,r,1,n)<<endl;
        }
    }
	
}
signed main()
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