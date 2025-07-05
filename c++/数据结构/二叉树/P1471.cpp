#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=1e5+5;
double v[maxn];
int n,m;
struct note
{
    double sum,sum_2,tag;
    note operator+ (const note &q)
    {
        note a;
        a.sum_2=sum_2+q.sum_2;
        a.sum=sum+q.sum;
        a.tag=0;
        return a;
    }
}tree[maxn*4];
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
    tree[x]=tree[x*2]+tree[x*2+1];
    return;
}
void add_note(int root,int l,int r,double x)
{
    tree[root].sum_2=tree[root].sum_2+(r-l+1)*(x*x)+2*x*tree[root].sum;
    tree[root].sum=tree[root].sum+(r-l+1)*x;
    return;
}
void push_down(int root,int l,int r)
{
    if(tree[root].tag==0)
        return;
    int mid=(r+l)/2;
    double x=tree[root].tag;
    add_note(ls(root),l,mid,x);
    add_note(rs(root),mid+1,r,x);
    tree[ls(root)].tag+=x;
    tree[rs(root)].tag+=x;
    tree[root].tag=0;
}
void build(int root,int l,int r)
{
    if(l==r)
    {
        tree[root].sum=v[l];
        tree[root].sum_2=pow(v[l],2);
        tree[root].tag=0;
    }    
    else
    {
        int mid=l+((r-l)>>1);
        build(root<<1,l,mid);
        build((root<<1)+1,mid+1,r);
        push_up(root);
    }
    return;
}
void add(int root,int l1,int r1,int l,int r,double x)//根，根包含的，包含的，要改的，+1，改变数值
{
    if(l1==l&&r1==r)
    {
        add_note(root,l,r,x);
        tree[root].tag+=x;
        return;
    }
    push_down(root,l1,r1);
    int mid=(l1+r1)/2;
    if(r<=mid)
    {
        add(root*2,l1,mid,l,r,x);
    }
    else
    {
        if(l>mid)
            add(root*2+1,mid+1,r1,l,r,x);
        else
        {
            add(root*2,l1,mid,l,mid,x);
            add((root*2)+1,mid+1,r1,mid+1,r,x);
        }
    }
    push_up(root);
    return;
}
double find_sum(int root, int l, int r, int l1, int r1)
{
    if (l == l1 && r == r1)
        return tree[root].sum;
    push_down(root, l1, r1);
    int mid = (l1 + r1) / 2;
    if (r <= mid)
        return find_sum(ls(root), l, r, l1, mid);
    else if (l > mid)
        return find_sum(rs(root), l, r, mid + 1, r1);
    else
        return find_sum(ls(root), l, mid, l1, mid) + find_sum(rs(root), mid + 1, r, mid + 1, r1);
}
double find_2(int root, int l, int r, int l1, int r1)
{
    if (l == l1 && r == r1)
        return tree[root].sum_2;
    push_down(root, l1, r1);
    int mid = (l1 + r1) / 2;
    if (r <= mid)
        return find_2(ls(root), l, r, l1, mid);
    else if (l > mid)
        return find_2(rs(root), l, r, mid + 1, r1);
    else
        return find_2(ls(root), l, mid, l1, mid) + find_2(rs(root), mid + 1, r, mid + 1, r1);
}
void solve()
{
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
        cin>>v[i];
    build(1,1,n);
    for (int i = 0; i < m; i++)
    {
        double x,y,k;
        int op;
        cin>>op;
        switch (op)
        {
        case 1:
            cin>>x>>y>>k;
            add(1,1,n,x,y,k);
            break;
        case 2:
            cin>>x>>y;
            printf("%.4f\n",find_sum(1,x,y,1,n)/(y-x+1));
            break;
        case 3:
            cin>>x>>y;
            double xb=find_sum(1,x,y,1,n)/(y-x+1),xf=find_2(1,x,y,1,n);
            double end=xf/(y-x+1)-pow(xb,2);
            printf("%.4f\n",end);
            break;
        }
    }
    
    
}
int main()
{
    solve();
    return 0;
}