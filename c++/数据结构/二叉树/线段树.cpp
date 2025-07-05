#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,MAXN=5e5+5;
ll tree[4*MAXN],tag[4*MAXN],where[MAXN];
ll v[MAXN],n,m;
void update(int x)
{
    if(x!=1)
    {
        tree[x/2]=tree[x]+tree[x^1];
        update(x/2);
    }
    return;
}
void push_up(int x)
{
    tree[x]=tree[x*2]+tree[x*2+1];
    return;
}
void push_down(int root,int l,int r)
{
    tree[root]+=tag[root]*(r-l+1);
    tag[root*2]+=tag[root];
    tag[root*2+1]+=tag[root];
    tag[root]=0;
    return;
}
void build(int root,int l,int r)
{
    tag[root]=0;
    if(l==r)
    {
        tree[root]=v[l];
        where[l]=root;
    }    
    else
    {
        int mid=l+((r-l)>>1);
        build(root<<1,l,mid);
        build((root<<1)+1,mid+1,r);
        tree[root]=tree[root<<1]+tree[(root<<1)+1];
        push_up(root);
    }
    return;
}
void one_change(int x,ll add)//第x个数，加y
{
    tree[where[x]]+=add;
    update(where[x]);
}
void scan()
{   
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>v[i];
    } 
    return;
}
ll find(int root,int l,int r,int l1,int r1)//l,r查的范围，l1,r1根节点包含的范围
{
    if(tag[root]!=0)
        push_down(root,l1,r1);
    if(l==l1&&r==r1)
        return tree[root];
    else
    {
        int mid=(l1+r1)/2;
        if(r<=mid)
            return find(root*2,l,r,l1,mid);
        else
        {
            if(l>=mid+1)
                return find(root*2+1,l,r,mid+1,r1);
            else
                return find(root*2,l,mid,l1,mid)+find(root*2+1,mid+1,r,mid+1,r1);
        }
    }  
}
void these_change(int root,int l,int r,int l1,int r1,ll add)//l,r改的范围，l1,r1根节点包含的范围,add加
{
    if(tag[root]!=0)
        push_down(root,l1,r1);
    int mid=l1+(r1-l1)/2;
    if(l==l1&&r==r1)//同个区间
    {
        //tree[root]+=add*(r-l+1);
        if(l!=r) 
            tag[root]+=add;
        else//叶子节点
            tree[root]+=add;
    }
    else
    {
        if(r<=mid)
        {
            tree[root]+=(r-l+1)*add;
            these_change(root*2,l,r,l1,mid,add);
        }
        else
        {
            if(l>mid)
            {
                tree[root]+=(r-l+1)*add;
                these_change(root*2+1,l,r,mid+1,r1,add);
            }
            else
            {
                tree[root]+=(r-l+1)*add;
                these_change(root*2,l,mid,l1,mid,add);
                these_change((root*2)+1,mid+1,r,mid+1,r1,add);
            }
        }
    }
    return;
}
void solve()
{
    scan();
    build(1,1,n);
    while(m--)
    {
        int make;
        cin>>make;
        if(make==1)
        {
            ll l,r,add;
            cin>>l>>r>>add;
            these_change(1,l,r,1,n,add);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<find(1,l,r,1,n)<<endl;
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