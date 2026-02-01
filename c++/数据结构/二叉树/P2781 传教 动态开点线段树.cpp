#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef pair<int,int> pii;
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

struct SegmentTree
{
    int cnt = 1;

    struct Node
    {
        int left, right;
        int val, lazy;
    };

    vector<Node> tree;

    SegmentTree()
    {
        tree.resize(8e4 + 5);
    }

    void lzay(int root,int val,int l,int r)
    {
        tree[root].lazy += val;
        tree[root].val += (r - l + 1) * val;
    }

    void down(int root,int l,int r)
    {
        if (l==r)
            return;
        if (tree[root].lazy)
        {
            int mid = (l + r) / 2;
            if (tree[root].left == 0)
            {
                tree[root].left = ++cnt;
            }
            if (tree[root].right == 0)
            {
                tree[root].right = ++cnt;
            }
            lzay(tree[root].left, tree[root].lazy, l, mid);
            lzay(tree[root].right, tree[root].lazy, mid + 1, r);
            tree[root].lazy = 0;
        }
    }

    void up(int root)
    {
        tree[root].val = tree[tree[root].left].val + tree[tree[root].right].val;
    }

    void updata(int root,int job_l,int job_r,int val,int l,int r)
    {
        if (job_l <= l && r <= job_r)
        {
            lzay(root, val, l, r);
            return;
        }
        down(root, l, r);
        int mid = (l + r) / 2;
        if (job_l <= mid)
        {
            if (tree[root].left == 0)
            {
                tree[root].left = ++cnt;
            }
            updata(tree[root].left, job_l, job_r, val, l, mid);
        }
        if (job_r > mid)
        {
            if (tree[root].right == 0)
            {
                tree[root].right = ++cnt;
            }
            updata(tree[root].right, job_l, job_r, val, mid + 1, r);
        }
        up(root);
    }

    int query(int root,int job_l,int job_r,int l,int r)
    {
        if (job_l <= l && r <= job_r)
        {
            return tree[root].val;
        }
        down(root, l, r);
        int mid = (l + r) / 2;
        int sum = 0;
        if (job_l <= mid)
        {
            if (tree[root].left != 0)
            {
                sum += query(tree[root].left, job_l, job_r, l, mid);
            }
        }
        if (job_r > mid)
        {
            if (tree[root].right != 0)
            {
                sum += query(tree[root].right, job_l, job_r, mid + 1, r);
            }
        }
        return sum;
    }
};

void solve()
{
    int n=read(),m=read();
    SegmentTree tree;
    for (int i=0;i<m;i++)
    {
        int op=read();
        if (op==1)
        {
            int x=read(),y=read(),k=read();
            tree.updata(1,x,y,k,1,n);
        }
        else
        {
            int x=read(),y=read();
            cout<<tree.query(1,x,y,1,n)<<endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //t = read();
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 2026/2/1.
//
