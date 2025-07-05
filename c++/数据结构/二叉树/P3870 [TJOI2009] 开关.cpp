#include<bits/stdc++.h>
using namespace std;
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1e5+5;
ll tree[4*maxn],tag[4*maxn];
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
void change(int root,int l,int r,int tag)
{
    if(tag%2==0)//按两次等于没按
        return;
    tree[root]=r-l+1-tree[root];
    push_up(root/2);
    return;
}
void push_down(int root,int l,int r)
{
    if(root*2>4*maxn)
        return;
    int mid=(l+r)/2;
    if(tag[root]!=0)
    {
        change(ls(root),l,mid,tag[root]);
        change(rs(root),mid+1,r,tag[root]);
        tag[ls(root)]+=tag[root];
        tag[rs(root)]+=tag[root];
        tag[root]=0;
    }
    return;
}
int find(int root,int l,int r,int l1,int r1)
{
    if(tag[root]!=0)
        push_down(root,l1,r1);
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
void these_change(int root,int l,int r,int l1,int r1)
{
    if(tag[root]!=0)
        push_down(root,l1,r1);
    if(l1==l&&r==r1)
    {
        change(root,l,r,1);
        tag[root]+=1;
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
int main()
{
    int n,m,c,a,b;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d%d",&c,&a,&b);
        if(c==0)
            these_change(1,a,b,1,n);
        else
            printf("%d\n",find(1,a,b,1,n));
    }
    return 0;
}