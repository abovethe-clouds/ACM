#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int maxn=1e6+5;
ll m,n,q,arr[maxn];
struct point
{
    ll data,lazy_tag_add,lazy_tag_x;
}tree[4*maxn];
int rs(int x)
{
    return x*2;
}
int ls(int x)
{
    return x*2+1;
}
void push_up(int x)
{
    tree[x].data=tree[ls(x)].data+tree[rs(x)].data;
    tree[x].data%=m;
    return;
}
void push_down(int root,int l,int r)
{
    if(l==r) return; //叶子节点
    int mid=(l+r)/2;
    
    if(tree[root].lazy_tag_x!=1)//存在乘法tag
    {
        tree[rs(root)].data*=tree[root].lazy_tag_x;
        tree[ls(root)].data*=tree[root].lazy_tag_x;
        tree[rs(root)].data%=m;
        tree[ls(root)].data%=m;
        tree[rs(root)].lazy_tag_x*=tree[root].lazy_tag_x;
        tree[rs(root)].lazy_tag_x%=m;
        tree[ls(root)].lazy_tag_x*=tree[root].lazy_tag_x;
        tree[ls(root)].lazy_tag_x%=m;
        tree[ls(root)].lazy_tag_add=(tree[ls(root)].lazy_tag_add*tree[root].lazy_tag_x)%m;
		tree[rs(root)].lazy_tag_add=(tree[rs(root)].lazy_tag_add*tree[root].lazy_tag_x)%m;
        tree[root].lazy_tag_x=1;
    }
    if(tree[root].lazy_tag_add)//存在加法tag
    {
        tree[rs(root)].data+=tree[root].lazy_tag_add*(mid-l+1);
        tree[ls(root)].data+=tree[root].lazy_tag_add*(r-mid);
        tree[rs(root)].data%=m;
        tree[ls(root)].data%=m;
        tree[rs(root)].lazy_tag_add+=tree[root].lazy_tag_add;
        tree[ls(root)].lazy_tag_add+=tree[root].lazy_tag_add;
        tree[rs(root)].lazy_tag_add%=m;
		tree[ls(root)].lazy_tag_add%=m;
        tree[root].lazy_tag_add=0;
    }
    push_up(root);
    return;
}
void add(int root,int l_change_range,int r_change_range,int l_point_range,int r_point_range,int change)
{
    if(l_change_range==l_point_range&&r_change_range==r_point_range)//正确的区间
    {
        if(l_change_range!=r_change_range)//不是叶子节点
        {
            push_down(root,l_point_range,r_point_range);
        }
        tree[root].lazy_tag_add+=change;
        tree[root].data+=change*(r_change_range-l_change_range+1);
        tree[root].data%=m;
        return;
    }
    push_down(root,l_point_range,r_point_range);//释放tag
    int mid=(l_point_range+r_point_range)/2;
    if(r_change_range<=mid)
        add(rs(root),l_change_range,r_change_range,l_point_range,mid,change);
    else if(l_change_range>mid)
        add(ls(root),l_change_range,r_change_range,mid+1,r_point_range,change);
    else
    {
        add(rs(root),l_change_range,mid,l_point_range,mid,change);
        add(ls(root),mid+1,r_change_range,mid+1,r_point_range,change);
    }
    push_up(root);
    return;
}
void x(int root,int l_change_range,int r_change_range,int l_point_range,int r_point_range,int change)
{
    if(l_change_range==l_point_range&&r_change_range==r_point_range)//正确的区间
    {
        if(l_change_range!=r_change_range)//不是叶子节点
        {
            push_down(root,l_point_range,r_point_range);
        }
        tree[root].lazy_tag_x*=change;
        tree[root].lazy_tag_x%=m;
        tree[root].data*=change;
        tree[root].data%=m;
        return;
    }
    push_down(root,l_point_range,r_point_range);//释放tag
    int mid=(l_point_range+r_point_range)/2;
    if(r_change_range<=mid)
        x(rs(root),l_change_range,r_change_range,l_point_range,mid,change);
    else if(l_change_range>mid)
        x(ls(root),l_change_range,r_change_range,mid+1,r_point_range,change);
    else
    {
        x(rs(root),l_change_range,mid,l_point_range,mid,change);
        x(ls(root),mid+1,r_change_range,mid+1,r_point_range,change);
    }
    push_up(root);
    return;
}
void scanf()
{
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    return;
}
void build(int root,int l,int r)
{
    tree[root].lazy_tag_add=0;
    tree[root].lazy_tag_x=1;
    if(l==r)
    {
        tree[root].data=arr[l]%m;
        tree[root].lazy_tag_add=0;
        tree[root].lazy_tag_x=1;
        return;
    }
    int mid=(l+r)/2;    
    build(rs(root),l,mid);
    build(ls(root),mid+1,r);
    push_up(root);
}
ll find(int root,int l_find_range,int r_find_range,int l_point_range,int r_point_range)
{
    if(l_find_range==l_point_range&&r_find_range==r_point_range)//正确的区间
    {
        if(l_find_range!=r_find_range)//不是叶子节点
        {
            push_down(root,l_point_range,r_point_range);
        }
        return tree[root].data%m;
    }
    push_down(root,l_point_range,r_point_range);//释放tag
    int mid=(l_point_range+r_point_range)/2;
    if(r_find_range<=mid)
        return find(rs(root),l_find_range,r_find_range,l_point_range,mid);
    else if(l_find_range>mid)
        return find(ls(root),l_find_range,r_find_range,mid+1,r_point_range);
    else
    {
        return find(rs(root),l_find_range,mid,l_point_range,mid)+find(ls(root),mid+1,r_find_range,mid+1,r_point_range);
    }
}
void solve()
{
    cin>>n>>q>>m;
    scanf();
    build(1,1,n);
    while(q--)
    {
        int op;
        cin>>op;
        int l,r,change;
        switch(op)
        {
            case 1:
                cin>>l>>r>>change;
                change%=m;
                x(1,l,r,1,n,change);
                break;
            case 2:
                change%=m;
                cin>>l>>r>>change;
                add(1,l,r,1,n,change);
                break;
            case 3:
                cin>>l>>r;
                cout<<find(1,l,r,1,n)%m<<endl;
                break;
        }
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