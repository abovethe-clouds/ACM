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
int n,m;
struct  point
{
    int num_1,num_0,first_num,first_long,end_num,end_long,long_num_1,long_num_0,tag=-1,tag_re=0;
    point operator+(point o)const
    {
        point n;
        if(end_num==o.first_num)
        {
            int maybelong = end_long + o.first_long;
            if(end_num==1)
            {
                if(maybelong>long_num_1)
                    n.long_num_1=maybelong;
                else
                    n.long_num_1=max(long_num_1,o.long_num_1);
                n.long_num_0=max(long_num_0,o.long_num_0);
            }
            else
            {
                if(maybelong>long_num_0)
                    n.long_num_0=maybelong;
                else
                    n.long_num_0=max(long_num_0,o.long_num_0);
                n.long_num_1=max(long_num_1,o.long_num_1);    
            }
        }
        else
        {
            n.long_num_1=max(long_num_1,o.long_num_1);
            n.long_num_0=max(long_num_0,o.long_num_0);
        }
        n.num_0=num_0+o.num_0;
        n.num_1=num_1+o.num_1;
        n.first_num=first_num;
        n.end_num=o.end_num;
        if(first_long==num_0+num_1&&first_num==o.first_num)
            n.first_long=num_0+num_1+o.first_long;
        else
            n.first_long=first_long;
        if(o.end_long==o.num_0+o.num_1&&o.first_num==end_num)
            n.end_long=o.num_0+o.num_1+o.end_long;
        else
            n.end_long=o.end_long;
        n.tag=-1,n.tag_re=0;
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
}
void point_change(int root,int l,int r,int c)
{
    tree[root].end_long=r-l+1;
    tree[root].first_long=r-l+1;
    tree[root].end_num=c;
    tree[root].first_num=c;
    if(c==0)
    {
        tree[root].long_num_0=r-l+1;
        tree[root].num_0=r-l+1;
        tree[root].long_num_1=0;
        tree[root].num_1=0;
    }
    else
    {
        tree[root].long_num_1=r-l+1;
        tree[root].num_1=r-l+1;
        tree[root].long_num_0=0;
        tree[root].num_0=0;
    }
    tree[root].tag=c;
    tree[root].tag_re=0;
}
void point_re(int root)
{
    swap(tree[root].num_0,tree[root].num_1);
    swap(tree[root].long_num_1,tree[root].long_num_0);
    tree[root].first_num^=1;
    tree[root].end_num^=1;
    tree[root].tag_re=1;
}
void push_down(int root,int l,int r)
{
    int mid=(l+r)/2;
    if(tree[root].tag!=-1)
    {
        point_change(ls(root),l,mid,tree[root].tag);
        point_change(rs(root),mid+1,r,tree[root].tag);
        tree[root].tag=-1;
    }
    if(tree[root].tag_re)
    {
        point_re(ls(root));
        point_re(rs(root));
        tree[root].tag_re=0;
    }
    push_up(root);
}
point find(int root,int l,int r,int L,int R)
{
    if(l==L&&r==R)
        return tree[root];
    push_down(root,L,R);
    int mid=(L+R)/2;
    if(r<=mid)
        find(ls(root),l,r,L,mid);
    else if(l>mid)
        find(rs(root),l,r,mid+1,R);
    else
    {
        find(ls(root),l,mid,L,mid);
        find(rs(root),mid+1,r,mid+1,R);
    }
}
void chang(int root,int l,int r,int L,int R,int change)
{
    if(l==L&&r==R)
    {
        point_change(root,l,r,change);
        return;
    }
    push_down(root,L,R);
    int mid=(L+R)/2;
    if(r<=mid)
        chang(ls(root),l,r,L,mid,change);
    else if(l>mid)
        chang(rs(root),l,r,mid+1,R,change);
    else
    {
        chang(ls(root),l,mid,L,mid,change);
        chang(rs(root),mid+1,r,mid+1,R,change);
    }
    push_up(root);
}
void reverse(int root,int l,int r,int L,int R)
{
    if(l==L&&r==R)
    {
        point_re(root);
        return;
    }
    push_down(root,L,R);
    int mid=(L+R)/2;
    if(r<=mid)
        reverse(ls(root),l,r,L,mid);
    else if(l>mid)
        reverse(rs(root),l,r,mid+1,R);
    else
    {
        reverse(ls(root),l,mid,L,mid);
        reverse(rs(root),mid+1,r,mid+1,R);
    }
    push_up(root);
}
void built(int root,int l,int r)
{
    if(l==r)
    {
        tree[root].end_long=1;
        tree[root].first_long=1;

    }
    int mid=(l+r)/2;
    built(ls(root),l,mid);
    built(rs(root),mid+1,r);
    push_up(root);
    return;
}
void scan()
{
    cin>>n>>m;
    for (int i = 1; i < n+1; i++)
        cin>>v[i];
    return;
}
void solve()
{
    scan();
    while (m--)
    {
        int op,l,r;
        cin>>op>>l>>r;
        switch (op)
        {
        case 0:
            chang(1,l,r,1,n,0);
            break;
        case 1:
            chang(1,l,r,1,n,1);
            break;
        case 2:
            reverse(1,l,r,1,n);
            break;
        case 3:
            cout<<find(1,l,r,1,n).num_1<<endl;
            break;
        case 4:
            cout<<find(1,l,r,1,n).long_num_1<<endl;
            break;
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