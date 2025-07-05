#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int inf = 0x3f3f3f3f, P = 131, maxn = 2e5 + 5;
#define int ll
int mod;
int read()
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
int end = 0, tree[4 * maxn];
int ls(int x)
{
    return x * 2;
}
int rs(int x)
{
    return x * 2 + 1;
}
int merge(int x, int y)
{
    return max(x, y);
}
void push_up(int x)
{
    tree[x] = merge(tree[(ls(x))], tree[rs(x)]);
}
int find(int root, int l, int r, int l1, int r1) // 前find 后root
{
    if (l == l1 && r == r1)
        return tree[root];
    int mid = (l1 + r1) >> 1;
    if (r <= mid)
        return find(ls(root), l, r, l1, mid);
    else
    {
        if (l > mid)
            return find(rs(root), l, r, mid + 1, r1);
        else
            return merge(find(ls(root), l, mid, l1, mid), find(rs(root), mid + 1, r, mid + 1, r1));
    }
}
void add(int root, int l, int r, int l1, int r1, int add1)
{
    if (l == l1 && r == r1)
    {
        tree[root] += add1;
        return;
    }
    int mid = (l1 + r1) >> 1;
    if (r <= mid)
        add(ls(root), l, r, l1, mid, add1);
    else
    {
        if (l > mid)
            add(rs(root), l, r, mid + 1, r1, add1);
        else
            add(ls(root), l, mid, l1, mid, add1), add(rs(root), mid + 1, r, mid + 1, r1, add1);
    }
    push_up(root);
    return;
}
void solve()
{
    int n;
    cin >> n >> mod;
    int h = 1, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        char op;
        cin >> op;
        if (op == 'Q')
        {
            int l;
            cin >> l;
            cnt = find(1, h - l, h - 1, 1, maxn);
            cout << cnt << endl;
        }
        else
        {
            int o;
            cin >> o;
            o += cnt;
            o += mod;
            o %= mod;
            add(1, h, h, 1, maxn, o);
            h++;
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
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}