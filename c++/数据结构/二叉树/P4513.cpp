#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=5e5+5;
int start[maxn],where[maxn];
struct note
{
    int max_f,max_e,max_s,s;
    note operator+(const note &e) const
    {
        note self;
        self.s=s+e.s;
        self.max_f=max(max_f,s+e.max_f);
        self.max_e=max(e.max_e,max_e+e.s);
        self.max_s=max(max_s,max(e.max_s,max_e+e.max_f));
        return self;
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
    tree[x]=tree[ls(x)]+tree[rs(x)];
    return;
}

void built(int root,int l,int r)
{
    if(l==r)
    {
        tree[root].s=start[l];
        tree[root].max_e=start[l];
        tree[root].max_f=start[l];
        tree[root].max_s=start[l];
        where[l]=root;
        return;
    }
    int mid=(l+r)>>1;
    built(ls(root),l,mid);
    built(rs(root),mid+1,r);
    push_up(root);
}
void push_up_1(int x)
{
    if(x==1)
        return;
    push_up(x/2);
    push_up_1(x/2);
}
void change(int w,int x)
{
    tree[where[w]].s=x;
    tree[where[w]].max_e=x;
    tree[where[w]].max_f=x;
    tree[where[w]].max_s=x;
    push_up_1(where[w]);
}
note find(int root,int l,int r,int l1,int r1)
{
    if(r1==r&&l1==l)
        return tree[root];
    int mid=(l+r)>>1;
    if(r1<=mid)
        return find(ls(root),l,mid,l1,r1);
    if(l1>mid) return find(rs(root),mid+1,r,l1,r1);
    return find(ls(root),l,mid,l1,mid)+find(rs(root),mid+1,r,mid+1,r1);
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>start[i];
    }
    built(1,1,n);
    while(m--)
    {
        int a,b,k;
        cin>>k>>a>>b;
        
        if(k==1)
        {
            if(a>b)
                swap(a,b);
            cout<<find(1,1,n,a,b).max_s<<endl;
        }
            
        else
            change(a,b);
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