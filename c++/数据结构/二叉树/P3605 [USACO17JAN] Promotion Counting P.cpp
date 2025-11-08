#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int long long
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=1e5+10;
int read()
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
int n,cnt=0;
struct value_compression
{
    vector<int> value;
    void push(int x)
    {
        value.push_back(x);
    }
    void _sort()
    {
        sort(value.begin(),value.end());
        value.erase(unique(value.begin(),value.end()), value.end());
    }
    int get_id(int x)
    {
        return  lower_bound(value.begin(),value.end(),x)-value.begin()+1;
    }
    int old_value(int x)
    {
        x--;
        return value[x];
    }
}compression;
struct tree_node
{
    int dfs,size=1,vul;
    vector<int> road;
}node[maxn];
struct PresidentTree {
    static constexpr int N = maxn + 10;
    int cntNodes, root[N];
    struct node {
        int l, r;
        int size=0;
    } point[40 * N];
    int build(int l, int r)
    {
        int rot = ++cntNodes;
        point[rot].size=0;
        if (l==r)
            return rot;
        int mid = (l + r) / 2;
        point[rot].l=build(l,mid);
        point[rot].r=build(mid+1,r);
        return rot;
    }
    void start()
    {
        root[0]=build(1,N);
    }
    int cnt_tree=1;
    void push_up(int x)
    {
        point[x].size = point[point[x].l].size + point[point[x].r].size;
    }

    int insert(int l,int r,int x,int before_root)
    {
        int rot=++cntNodes;
        point[rot]=point[before_root];
        if (l==r)
        {
            point[rot].size++;
            return rot;
        }
        int mid = (l + r) / 2;
        if (x<=mid)
        {
            point[rot].l=insert(l,mid,x,point[rot].l);
        }
        else
        {
            point[rot].r=insert(mid+1,r,x,point[rot].r);
        }
        push_up(rot);
        return rot;
    }
    void insert1(int x)
    {
        root[cnt_tree] = insert(1, N, x, root[cnt_tree-1]);
        cnt_tree++;
    }
    int _qurey(int l_val,int r_val,int l,int r,int root_l,int root_r)
    {
        if (l_val==l && r_val==r)
        {
            return point[root_r].size-point[root_l].size;
        }
        int mid = (l + r) / 2;
        int ans=0;
        if (r_val<=mid)
        {
            ans+=_qurey(l_val,r_val,l,mid,point[root_l].l,point[root_r].l);
        }
        else if (l_val>mid)
        {
            ans+=_qurey(l_val,r_val,mid+1,r,point[root_l].r,point[root_r].r);
        }
        else
        {
            ans+=_qurey(l_val,mid,l,mid,point[root_l].l,point[root_r].l);
            ans+=_qurey(mid+1,r_val,mid+1,r,point[root_l].r,point[root_r].r);
        }
        return ans;

    }
    int qurey(int x,int l,int r)
    {
        return _qurey(x+1,N,1,N,root[l-1],root[r]);
    }
}tree;
vector<int> v;
void input()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        int x=read();
        node[i].vul=x;
        compression.push(x);
    }
    for (int i=2;i<=n;i++)
    {
        node[read()].road.push_back(i);
    }
    compression._sort();
}
int dfs(int x)
{
    node[x].vul=compression.get_id(node[x].vul);
    node[x].dfs=++cnt;
    tree.insert1(node[x].vul);
    for (auto i : node[x].road)
    {
        dfs(i);
        node[x].size+=node[i].size;
    }

    return node[x].size;
}
void solve()
{
    input();
    tree.start();
    dfs(1);
    for (int i=1;i<=n;i++)
    {
        cout<<tree.qurey(node[i].vul,node[i].dfs,node[i].dfs+node[i].size-1)<<endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //t=read();
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2025/11/8.
//