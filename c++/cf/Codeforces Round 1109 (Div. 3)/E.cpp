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
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;

struct seg_point
{
    int n, _0cnt, _1cnt;
};

seg_point merge(seg_point a, seg_point b)
{
    seg_point m;
    m.n = a.n + b.n;
    if (a.n % 2 == 0)
    {
        m._0cnt = a._0cnt + b._0cnt;
        m._1cnt = a._1cnt + b._1cnt;
    }
    else
    {
        m._1cnt = a._1cnt + b._0cnt;
        m._0cnt = a._0cnt + b._1cnt;
    }
    return m;
}

struct seg_tree
{
    vector<seg_point> tree;
    int n;

    seg_tree(int _n)
    {
        n = _n;
        tree.resize(4 * (n + 5));
    }

    void build(int node, int l, int r, vector<int>& a)
    {
        if (l == r)
        {
            tree[node].n = 1;
            if (a[l] == 0)
            {
                tree[node]._0cnt = 0;
                tree[node]._1cnt = 1;
            }
            else
            {
                tree[node]._0cnt = 1;
                tree[node]._1cnt = 0;
            }
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, a);
        build(2 * node + 1, mid + 1, r, a);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    seg_point query(int node, int rl, int rr, int l, int r)
    {
        if (l <= rl && rr <= r)
        {
            return tree[node];
        }
        int mid = (rl + rr) / 2;
        if (r <= mid)
        {
            return query(node * 2, rl, mid, l, r);
        }
        else if (l > mid)
        {
            return query(node * 2 + 1, mid + 1, rr, l, r);
        }
        else
        {
            seg_point left = query(node * 2, rl, mid, l, r);
            seg_point right = query(node * 2 + 1, mid + 1, rr, l, r);
            return merge(left, right);
        }
    }
};

int count(vector<int>& v)
{
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 1 && (i == 0 || v[i - 1] == 0))
            ans++;
    }
    return ans;
}

struct fast_query_1
{
    vector<int> pre;
    vector<int> v;

    explicit fast_query_1(vector<int>& a)
    {
        v = a;
        int n = a.size();
        pre.resize(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int start = (a[i] == 1 && (i == 0 || a[i - 1] == 0));
            pre[i + 1] = pre[i] + start;
        }
    }

    int query(int l, int r)
    {
        int ans = pre[r + 1] - pre[l];
        if (l > 0 && v[l] == 1 && v[l - 1] == 1)
            ans++;
        return ans;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    string s1, s2;
    s1.push_back('1');
    s2.push_back('0');
    for (int i = 1; i < n; i++)
    {
        s1.push_back(s1.back() == '1' ? '0' : '1');
        s2.push_back(s2.back() == '1' ? '0' : '1');
    }
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == s1[i])
            a[i] = 0;
        else
            a[i] = 1;
        if (s[i] == s2[i])
            b[i] = 0;
        else
            b[i] = 1;
    }
    fast_query_1 ans(a), ans2(b);
    for (int i = 0; i < m; i++)
    {
        int l, r, c;
        cin >> l >> r >> c;
        l--, r--;
        int u=min(ans.query(l, r), ans2.query(l, r));
        if (c>=u)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
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
    cin >> t;
    while (t--)
        solve();
    return 0;
}
