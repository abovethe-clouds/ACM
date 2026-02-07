#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<pii, pii> piiii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
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

struct DC
{
    vector<int> a;

    void add(int x)
    {
        a.push_back(x);
    }

    void build()
    {
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        a.push_back(a.back());
    }

    int getid(int x)
    {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1;
    }
} DC1,DC2;

struct _seg
{
    int x, y0, y1, val;
};

struct segment_tree
{
    struct Node
    {
        int time, length, cover;
    };

    vector<Node> tree;

    segment_tree(int n)
    {
        tree.resize((n + 5) * 4);
    }
    void up(int i,int l,int r)
    {
        if (tree[i].time>0)
            {tree[i].cover=tree[i].length;return;}
        if (l==r)
            tree[i].cover=0;
        else
            tree[i].cover=tree[ls(i)].cover+tree[rs(i)].cover;
    }
    void build(int rt, int l, int r, vector<int> &v)
    {
        tree[rt].time = 0;
        tree[rt].cover = 0;
        if (l == r)
        {
            tree[rt].length = v[l] - v[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(rt), l, mid, v);
        build(rs(rt), mid + 1, r, v);
        tree[rt].length = tree[ls(rt)].length + tree[rs(rt)].length;
    }

    void add(int rt,int l,int r,int job_l,int job_r,int val)
    {
        if (job_l<=l&&r<=job_r)
        {
            tree[rt].time+=val;
            up(rt,l,r);
            return;
        }
        int mid=(l+r)/2;
        if (job_l<=mid)
            add(ls(rt),l,mid,job_l,job_r,val);
        if (job_r>mid)
            add(rs(rt),mid+1,r,job_l,job_r,val);
        up(rt,l,r);
    }
    int query()
    {
        return tree[1].cover;
    }
};

void solve()
{
    int n = read();
    vector<_seg> yyy(n * 2),xxx(n*2);
    for (int i = 0; i < n; i++)
    {
        int x[2], y[2];
        for (int j = 0; j < 2; j++)
        {
            x[j] = read();
            y[j] = read();
        }
        sort(x, x + 2);
        sort(y, y + 2);
        yyy[i * 2] = {x[0], y[0], y[1], 1};
        yyy[i * 2 + 1] = {x[1], y[0], y[1], -1};
        xxx[i*2] = {y[0], x[0], x[1], 1};
        xxx[i*2+1] = {y[1], x[0], x[1], -1};
        DC1.add(y[0]);
        DC1.add(y[1]);
        DC2.add(x[0]);
        DC2.add(x[1]);
    }
    sort(yyy.begin(), yyy.end(), [](const _seg &a, const _seg &b)
    {
        if (a.x!=b.x)
            return a.x < b.x;
        return a.val > b.val;
    });
    sort(xxx.begin(), xxx.end(), [](const _seg &a, const _seg &b)
    {
        if (a.x!=b.x)
            return a.x < b.x;
        return a.val > b.val;
    });
    DC1.build();
    DC2.build();
    segment_tree seg(DC1.a.size()),seg1(DC2.a.size());
    seg.build(1, 1, DC1.a.size() - 1, DC1.a);
    seg1.build(1, 1, DC2.a.size() - 1, DC2.a);
    int ans = 0;
    for (int i=0,pre=0;i<yyy.size();i++)
    {
        seg.add(1,1,DC1.a.size()-1,DC1.getid(yyy[i].y0),DC1.getid(yyy[i].y1)-1,yyy[i].val);
        ans+=abs(pre-seg.query());
        pre=seg.query();
    }
    for (int i=0,pre=0;i<xxx.size();i++)
    {
        seg1.add(1,1,DC2.a.size()-1,DC2.getid(xxx[i].y0),DC2.getid(xxx[i].y1)-1,xxx[i].val);
        ans+=abs(pre-seg1.query());
        pre=seg1.query();
    }
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
// #ifndef ONLINE_JUDGE
//     freopen("test.in", "r", stdin);
//     freopen("test.out", "w", stdout);
// #endif
    int t = 1;
    //t = read();
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 2026/2/7.
//
