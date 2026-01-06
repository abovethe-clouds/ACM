#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
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

int n, m;

int ls(int x)
{
    return x * 2;
}

int rs(int x)
{
    return x * 2 + 1;
}

vector<int> v;
vector<pair<int, pii> > op;

struct node
{
    int cnt_1;
    int lazy; //1 0 -1没有
    node operator+(const node x) const
    {
        node res{};
        res.cnt_1 = cnt_1 + x.cnt_1;
        res.lazy = -1;
        return res;
    }
};

vector<node> tree; //线段树

void push_up(int root)
{
    tree[root] = tree[ls(root)] + tree[rs(root)];
}

void tree_fill(int root, int l, int r, int num)
{
    int size = r - l + 1;
    tree[root].lazy = num;
    tree[root].cnt_1 = num * size;
}

void push_down(int root, int l, int r)
{
    if (tree[root].lazy == -1)
        return;
    int mid = (l + r) / 2;
    tree_fill(ls(root), l, mid, tree[root].lazy);
    tree_fill(rs(root), mid + 1, r, tree[root].lazy);
    tree[root].lazy = -1;
}

void built(int root, int l, int r, int standard)
{
    if (l == r)
    {
        tree[root].cnt_1 = (v[l] >= standard) ? 1 : 0;
        tree[root].lazy = -1;
        return;
    }
    int mid = (l + r) / 2;
    built(root * 2, l, mid, standard);
    built(root * 2 + 1, mid + 1, r, standard);
    push_up(root);
}

void update(int root, int l, int r, int L, int R, int type)
{
    if (L == l && r == R)
    {
        tree[root].cnt_1 = type * (R - L + 1);
        tree[root].lazy = type;
        return;
    }
    push_down(root, l, r);
    int mid = (l + r) / 2;
    if (R <= mid)
        update(ls(root), l, mid, L, R, type);
    else if (L > mid)
        update(rs(root), mid + 1, r, L, R, type);
    else
        update(ls(root), l, mid, L, mid, type), update(rs(root), mid + 1, r, mid + 1, R, type);
    push_up(root);
}

node query(int root, int l, int r, int L, int R)
{
    if (L == l && r == R)
    {
        return tree[root];
    }
    push_down(root, l, r);
    int mid = (l + r) / 2;
    if (R <= mid)
        return query(ls(root), l, mid, L, R);
    if (L > mid)
        return query(rs(root), mid + 1, r, L, R);
    else
        return query(ls(root), l, mid, L, mid) + query(rs(root), mid + 1, r, mid + 1, R);
}

void opp(int l, int r, int o)
{
    int sum1 = query(1, 1, n, l, r).cnt_1;
    int len = r - l + 1;
    int sum0 = len - sum1;

    if (o == 0)
    {
        if (sum0 > 0)
            update(1, 1, n, l, l + sum0 - 1, 0);
        if (sum1 > 0)
            update(1, 1, n, l + sum0, r, 1);
    }
    else // 降序：1 在前，0 在后
    {
        if (sum1 > 0)
            update(1, 1, n, l, l + sum1 - 1, 1);
        if (sum0 > 0)
            update(1, 1, n, l + sum1, r, 0);
    }
}


bool check(int q)
{
    node res = query(1, 1, n, q, q);
    return res.cnt_1 == 1;
}

void ope(int x)
{
    built(1, 1, n, x);
    for (auto it: op)
    {
        opp(it.sec.fir, it.sec.sec, it.fir);
    }
}

void solve()
{
    n = read(), m = read();
    op.resize(m);
    v.resize(n + 1);
    tree.resize(4 * n + 4);
    for (int i = 1; i <= n; i++)
        v[i] = read();
    for (int i = 0; i < m; i++)
    {
        int a = read(), b = read(), c = read();
        op[i] = {a, {b, c}};
    }
    int ans = read();
    int i = 1, j = n;
    int l = 1, r = n, ansv = 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        ope(mid);
        if (check(ans))
        {
            ansv = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ansv << endl;
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

// 1 2 5 6 4 3