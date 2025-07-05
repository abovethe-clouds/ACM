#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int maxn=1e5+5;
ll tree[maxn*4],v[maxn];
int ls(int x)
{
    return x*2;
}
int rs(int x)
{
    return x*2+1;
}
void push_up(int root)
{
    tree[root]=tree[ls(root)]+tree[rs(root)];
    return;
}
void these_change(int root,int l,int r,int l1,int r1)
{
    if(l==l1&&r==r1)
    {
        if(l==r)
        tree[root]=sqrt(tree[root]);
        else
        {
            if(tree[root]==r1-l1+1)
                return;
            else
            {
                int mid=(l1+r1)/2;
                these_change(ls(root),l,mid,l1,mid);
                these_change(rs(root),mid+1,r,mid+1,r1);
                push_up(root);
            }
        }
    }
    else
    {
        int mid=(l1+r1)/2;
        if(r<=mid)
            these_change(ls(root),l,r,l1,mid);
        else
        {
            if(l>mid)
                these_change(rs(root),l,r,mid+1,r1);
            else
            {
                these_change(ls(root),l,mid,l1,mid);
                these_change(rs(root),mid+1,r,mid+1,r1);
            }
        }
        push_up(root);
    }
    return;
}
ll find(int root,int l,int r,int l1,int r1)
{
    if(l1==l&&r==r1)
        return tree[root];
    else
    {
        int mid=(l1+r1)/2;
        if(r<=mid)
            return find(ls(root),l,r,l1,mid);
        else
        {
            if(l>mid)
                return find(rs(root),l,r,mid+1,r1);
            else
            {
                return find(ls(root),l,mid,l1,mid)+find(rs(root),mid+1,r,mid+1,r1);
            }
        }
    }
}
void build(int root,int l,int r)
{
    if(l==r)
        tree[root]=v[l];
    else
    {
        int mid=(l+r)/2;
        build(ls(root),l,mid);
        build(rs(root),mid+1,r);
        push_up(root);
    }
    return;
}
void solve()
{
    int n,m;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",&v[i]);
    build(1,1,n);
    int k,l,r;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d%d%d",&k,&l,&r);
        if(r<l)
            swap(r,l);
        if(k==0)
            these_change(1,l,r,1,n);
        else
            printf("%lld\n",find(1,l,r,1,n));

    }
}
int main()
{
    solve();
	return 0;
}