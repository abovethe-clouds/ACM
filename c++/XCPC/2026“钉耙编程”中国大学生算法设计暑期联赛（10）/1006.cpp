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

struct Node
{
    int b, e, cnt;
    bool lazy1, lazy2, empty;
    int to;
    Node(int x)
    {
        if (x == 0x66CCFF)
        {
            empty = true;
        }
        else
        {
            b = e = x;
            cnt = 0;
            lazy1 = false;
            lazy2 = false;
            to = 0;
            empty = false;
        }
    }
    Node operator+(const Node &rhs)
    {
        Node res(0x66CCFF);
        if (empty)
            return rhs;
        if (rhs.empty)
            return *this;
        res.cnt = cnt + rhs.cnt;
        res.b = b;
        res.e = rhs.e;
        if ((e ^ rhs.b) == 1)
            res.cnt++;
        res.lazy1 = res.lazy2 = false;
        res.to = 0;
        res.empty = false;
        return res;
    }


};

struct seg_tree
{
    int n;
    vector<Node> tree;

    seg_tree(vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n, Node(0x66CCFF));
        n--;
        build(arr, 1, 1, n);
    }

    void build(vector<int> &arr,int node,int start,int end)
    {
        if (start == end)
        {
            tree[node] = Node(arr[start]);
        } else
        {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void push_down(int node,int start,int end)
    {
        if (start == end)
            return;
        if (tree[node].lazy1)
        {
            set_val(2 * node, tree[node].to);
            set_val(2 * node + 1, tree[node].to);
            tree[node].lazy1 = false;
        }
        if (tree[node].lazy2)
        {
            revserse(2 * node);
            revserse(2 * node + 1);
            tree[node].lazy2 = false;
        }
    }

    void set_val(int node,int val)
    {
        tree[node].b = tree[node].e = val;
        tree[node].cnt = 0;
        tree[node].lazy1 = true;
        tree[node].lazy2 = false;
        tree[node].to = val;
    }

    void revserse(int node)
    {
        tree[node].b ^= 1;
        tree[node].e ^= 1;
        if (tree[node].lazy1)
        {
            tree[node].to ^= 1;
        } else
        {
            tree[node].lazy2 ^= 1;
        }
    }

    void update1(int node,int start,int end,int l,int r,int val)
    {
        if (r < start || end < l)
            return;
        if (l <= start && end <= r)
        {
            set_val(node, val);
            return;
        }
        push_down(node, start, end);
        int mid = (start + end) / 2;
        update1(2 * node, start, mid, l, r, val);
        update1(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update2(int node,int start,int end,int l,int r)
    {
        if (r < start || end < l)
            return;
        if (l <= start && end <= r)
        {
            revserse(node);
            return;
        }
        push_down(node, start, end);
        int mid = (start + end) / 2;
        update2(2 * node, start, mid, l, r);
        update2(2 * node + 1, mid + 1, end, l, r);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    Node query(int node,int start,int end,int l,int r)
    {
        if (r < start || end < l)
            return Node(0x66CCFF);
        if (l <= start && end <= r)
        {
            return tree[node];
        }
        push_down(node, start, end);
        int mid = (start + end) / 2;
        Node p1 = query(2 * node, start, mid, l, r);
        Node p2 = query(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    seg_tree st(arr);
    for (int i = 0; i < m; i++)
    {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1)
        {
            int val;
            cin >> val;
            st.update1(1, 1, n, l, r, val);
        } else if (op == 2)
        {
            st.update2(1, 1, n, l, r);
        } else
        {
            Node res = st.query(1, 1, n, l, r);
            cout << res.cnt << endl;
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
    cin >> t;
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 2026/8/20.
//
