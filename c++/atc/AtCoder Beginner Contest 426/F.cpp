#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
#define int ull
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 3e5 + 5;

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
struct lazy_struct
{
    int l,r,k;
};
struct point
{
    int max_num, min_num;
    vector<lazy_struct> lazy;
};

vector<int> v(maxn);
point tree[4 * maxn];

int ls(int x)
{
    return x * 2;
}

int rs(int x)
{
    return x * 2 + 1;
}

point merge(const point a, const point b)
{
    point n{};
    n.max_num = max(a.max_num, b.max_num);
    n.min_num = min(a.min_num, b.min_num);
    return n;
}
void sub(int root,int l,int r,int k)
{
    tree[root].min_num -= k;
    tree[root].lazy.push_back({l, r,k});
}

point push_up(const int root)
{
    return tree[root] = merge(tree[ls(root)], tree[rs(root)]);
}
void push_down(int root,int l,int r)
{
    int mid = (l + r) / 2;
    for (auto i:tree[root].lazy)
    {
        if (i.r<=mid)
        {
            sub(ls(root),i.l,i.r,i.k);
        }
        else if (i.l>mid)
        {
            sub(rs(root),i.l,i.r,i.k);
        }
        else
        {
            sub(ls(root),i.l,mid,i.k);
            sub(rs(root),mid+1,i.r,i.k);
        }
    }
    push_up(root);
}
void built(int root, int l, int r)
{
    if (l == r)
    {
        tree[root].max_num = v[l];
        tree[root].min_num = v[l];
        return;
    }
    int mid = (l + r) / 2;
    built(ls(root), l, mid);
    built(rs(root), mid + 1, r);
    push_up(root);
}

int find(int root, int find_l, int find_r, int root_l, int root_r, int k)
{
    if (tree[root].max_num == 0)
        return 0;
    push_down(root,root_l,root_r);
    if (tree[root].min_num>=k)
    {
        tree[root].min_num -= k;
        tree[root].lazy.push_back({find_l, find_r,k});
        return k*(find_r-find_l+1);
    }
    if (root_l == root_r)
    {
        if (tree[root].min_num >= k)
        {
            tree[root].min_num -= k;
            tree[root].max_num -= k;
            return k;
        }
        else
        {
            int x = tree[root].min_num;
            tree[root].min_num = 0;
            tree[root].max_num = 0;
            return x;
        }
    }
    int mid = (root_l + root_r) / 2;
    if (find_r <= mid)
    {
        int x = find(ls(root), find_l, find_r, root_l, mid, k);
        push_up(root);
        return x;
    }
    if (find_l > mid)
    {
        int x=find(rs(root), find_l, find_r, mid + 1, root_r, k);
        push_up(root);
        return x;
    }
    int x=find(ls(root), find_l, mid, root_l, mid, k)+find(rs(root), mid + 1, find_r, mid + 1, root_r,k);
    push_up(root);
    return x;

}

void solve()
{
    int n = read();
    for (int i = 1; i <= n; i++)
        v[i] = read();
    built(1, 1, n);
    int q = read();
    while (q--)
    {
        int l = read(), r = read(), k = read();
        cout<<find(1, l, r, 1, n, k)<<endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();

    return 0;
}
