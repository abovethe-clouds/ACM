#include<bits/stdc++.h>
using namespace std;
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define int long long
const long long mod = 1e9 + 7, inf = LONG_LONG_MIN, P = 131;

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

struct point
{
    int mx, second_max, max_cnt;
    int add_max, add_other;
    long long sum;
    int history_max,max_add_Top,other_add_Top;
    point()
    {
        mx = second_max = inf;
        sum = 0ll;
        max_cnt = 0, add_max = add_other = 0;
        history_max= inf;
        max_add_Top=other_add_Top=0;
    }

    explicit point(int x)
    {
        mx = x;
        second_max = inf;
        max_cnt = 1;
        sum = x;
        add_max = add_other = 0;
        history_max=x;
        max_add_Top=other_add_Top=0;
    }

    point operator+(point const &p) const
    {
        point ans;
        ans.sum = sum + p.sum;
        ans.history_max= max(history_max,p.history_max);
        if (mx == p.mx)
        {
            ans.mx = mx;
            ans.max_cnt = max_cnt + p.max_cnt;
            ans.second_max = max(second_max, p.second_max);
        } else if (mx > p.mx)
        {
            ans.mx = mx;
            ans.max_cnt = max_cnt;
            ans.second_max = max(second_max, p.mx);
        } else
        {
            ans.mx = p.mx;
            ans.max_cnt = p.max_cnt;
            ans.second_max = max(mx, p.second_max);
        }
        return ans;
    }
};

struct segment_tree
{
    vector<point> tree;
    int n;

    segment_tree(int size)
    {
        n = size;
        tree.resize((size << 2)+40);
    }

    void push_up(int root)
    {
        tree[root] = tree[ls(root)] + tree[rs(root)];
    }

    void build(int root, int l, int r, vector<int> &a)
    {
        if (l == r)
        {
            tree[root] = point(a[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(root), l, mid, a);
        build(rs(root), mid + 1, r, a);
        push_up(root);
    }

    void build(vector<int> &a)
    {
        build(1, 1, n, a);
    }

    void lazy(int root, int max_add, int other_add, int n,int max_history_add,int other_history_add)
    {
        tree[root].history_max=max(tree[root].history_max,tree[root].mx+max_history_add);
        tree[root].max_add_Top=max(tree[root].max_add_Top,tree[root].add_max+max_history_add);
        tree[root].other_add_Top=max(tree[root].other_add_Top,tree[root].add_other+other_history_add);
        tree[root].sum += max_add * tree[root].max_cnt;
        tree[root].sum += (n - tree[root].max_cnt) * other_add;
        tree[root].add_max += max_add;
        tree[root].add_other += other_add;
        tree[root].mx += max_add;
        if (tree[root].second_max != inf)
            tree[root].second_max += other_add;
    }

    void down(int root, int l, int r)
    {
        if (tree[root].add_max == 0 && tree[root].add_other == 0)
            return;
        int temp = max(tree[ls(root)].mx, tree[rs(root)].mx);
        int mid = (l + r) >> 1;
        if (tree[ls(root)].mx == temp)
        {
            lazy(ls(root), tree[root].add_max, tree[root].add_other, mid - l + 1, tree[root].max_add_Top,tree[root].other_add_Top);
        } else
        {
            lazy(ls(root), tree[root].add_other, tree[root].add_other, mid - l + 1, tree[root].other_add_Top,tree[root].other_add_Top);
        }
        if (tree[rs(root)].mx == temp)
        {
            lazy(rs(root), tree[root].add_max, tree[root].add_other, r - mid, tree[root].max_add_Top,tree[root].other_add_Top);
        } else
        {
            lazy(rs(root), tree[root].add_other, tree[root].add_other, r - mid, tree[root].other_add_Top,tree[root].other_add_Top);
        }
        tree[root].add_max = 0;
        tree[root].add_other = 0;
        tree[root].max_add_Top=0;
        tree[root].other_add_Top=0;
    }

    void setMin(int root, int job_l, int job_r, int l, int r, int x)
    {
        if (x >= tree[root].mx)
            return;
        if (job_l <= l && r <= job_r && x > tree[root].second_max)
        {
            lazy(root, x - tree[root].mx, 0, r - l + 1, x - tree[root].mx,0);
            return;
        }
        down(root, l, r);
        int mid = (l + r) >> 1;
        if (job_l <= mid)
            setMin(ls(root), job_l, job_r, l, mid, x);
        if (job_r > mid)
            setMin(rs(root), job_l, job_r, mid + 1, r, x);
        push_up(root);
    }

    long long query_sum(int root, int job_l, int job_r, int l, int r)
    {
        if (job_l <= l && r <= job_r)
            return tree[root].sum;
        down(root, l, r);
        int mid = (l + r) >> 1;
        long long ans = 0;
        if (job_l <= mid)
            ans += query_sum(ls(root), job_l, job_r, l, mid);
        if (job_r > mid)
            ans += query_sum(rs(root), job_l, job_r, mid + 1, r);
        return ans;
    }

    int query_max(int root, int job_l, int job_r, int l, int r)
    {
        if (job_l <= l && r <= job_r)
            return tree[root].mx;
        down(root, l, r);
        int mid = (l + r) >> 1, ans = inf;
        if (job_l <= mid)
            ans = max(ans, query_max(ls(root), job_l, job_r, l, mid));
        if (job_r > mid)
            ans = max(ans, query_max(rs(root), job_l, job_r, mid + 1, r));
        return ans;
    }

    void updata_add(int root, int job_l, int job_r, int l, int r, int x)
    {
        if (job_l <= l && r <= job_r)
        {
            lazy(root, x, x, r - l + 1, x, x);
            return;
        }
        down(root, l, r);
        int mid = (l + r) >> 1;
        if (job_l <= mid)
            updata_add(ls(root), job_l, job_r, l, mid, x);
        if (job_r > mid)
            updata_add(rs(root), job_l, job_r, mid + 1, r, x);
        push_up(root);
    }
    int query_history_max(int root, int job_l, int job_r, int l, int r)
    {
        if (job_l <= l && r <= job_r)
            return tree[root].history_max;
        down(root, l, r);
        int mid = (l + r) >> 1, ans = inf;
        if (job_l <= mid)
            ans = max(ans, query_history_max(ls(root), job_l, job_r, l, mid));
        if (job_r > mid)
            ans = max(ans, query_history_max(rs(root), job_l, job_r, mid + 1, r));
        return ans;
    }
};

void solve()
{
    int n = read(), m = read();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = read();
    segment_tree seg(n);
    seg.build(a);
    for (int i = 1; i <= m; i++)
    {
        int op = read();
        if (op == 1)
        {
            int l = read(), r = read(), x = read();
            seg.updata_add(1, l, r, 1, n, x);
        } else if (op == 2)
        {
            int l = read(), r = read(),x= read();
            seg.setMin(1, l, r, 1, n, x);
        } else if (op==3)
        {
            int l = read(), r = read();
            cout << seg.query_sum(1, l, r, 1, n) << "\n";
        } else if (op == 4)
        {
            int l = read(), r = read();
            cout << seg.query_max(1, l, r, 1, n) << "\n";
        } else if (op == 5)
        {
            int l = read(), r = read();
            cout << seg.query_history_max(1, l, r, 1, n) << "\n";
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
    //t = read();
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 2026/1/29.
//
