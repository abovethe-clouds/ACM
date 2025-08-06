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

struct SegmentTree
{
    vector<ll> tree, tag;
    ll maxn;

    SegmentTree(int n) : maxn(n), tree(4 * n + 10, 0), tag(4 * n + 10, 0)
    {
    }

    void push_up(int x)
    {
        tree[x] = tree[x * 2] + tree[x * 2 + 1];
    }

    void push_down(int root, int l, int r)
    {
        if (l == r) return;
        if (tag[root] != 0)
        {
            int mid = (l + r) / 2;
            tag[root * 2] += tag[root];
            tree[root * 2] += (mid - l + 1) * tag[root];
            tag[root * 2 + 1] += tag[root];
            tree[root * 2 + 1] += (r - mid) * tag[root];
            tag[root] = 0;
        }
    }

    void build(int root, int l, int r)
    {
        tag[root] = 0;
        if (l == r)
        {
            tree[root] = 0;
        } else
        {
            int mid = (l + r) / 2;
            build(root * 2, l, mid);
            build(root * 2 + 1, mid + 1, r);
            push_up(root);
        }
    }

    ll find(int root, int l, int r, int l1, int r1)
    {
        push_down(root, l1, r1);
        if (l <= l1 && r1 <= r)
        {
            return tree[root];
        }
        int mid = (l1 + r1) / 2;
        ll res = 0;
        if (l <= mid)
            res += find(root * 2, l, r, l1, mid);
        if (r > mid)
            res += find(root * 2 + 1, l, r, mid + 1, r1);
        return res;
    }

    void these_change(int root, int l, int r, int l1, int r1, ll add)
    {
        push_down(root, l1, r1);
        if (l <= l1 && r1 <= r)
        {
            tree[root] += (r1 - l1 + 1) * add;
            tag[root] += add;
            return;
        }
        int mid = (l1 + r1) / 2;
        if (l <= mid)
            these_change(root * 2, l, r, l1, mid, add);
        if (r > mid)
            these_change(root * 2 + 1, l, r, mid + 1, r1, add);
        push_up(root);
    }

    void build()
    {
        build(1, 1, maxn);
    }

    ll query(int l, int r)
    {
        if (l > r) return 0;
        return find(1, l, r, 1, maxn);
    }

    void range_add(int l, int r, ll add)
    {
        if (l > r) return;
        these_change(1, l, r, 1, maxn, add);
    }

    void point_add(int x, ll add)
    {
        range_add(x, x, add);
    }
};

bool cmp(pii a, pii b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

void solve()
{
    int n;//如果去掉138行，此行换为int n=read(); 出错
    cin>>n;
    pii a[n];
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        v.push_back(a[i].first);
        v.push_back(a[i].second);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int N = v.size();
    map<pii, int> mp;
    for (int i = 0; i < n; i++)
    {
        int l = lower_bound(v.begin(), v.end(), a[i].first) - v.begin() + 1;
        int r = lower_bound(v.begin(), v.end(), a[i].second) - v.begin() + 1;
        a[i] = {l, r};
        mp[{l, r}] = i;
    }

    sort(a, a + n, cmp);
    SegmentTree tree(N);
    tree.build();
    int ans[n] = {0};
    for (int i = 0; i < n; i++)
    {
        int l = a[i].first;
        int r = a[i].second;
        ans[mp[{l, r}]] = tree.query(l, N);
        tree.point_add(l, 1);
    }
    for (int i: ans)
    {
        cout << i << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--)
        solve();
    return 0;
}
