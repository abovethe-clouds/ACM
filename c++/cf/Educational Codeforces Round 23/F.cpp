#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 2e5 + 5;

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

int ls(const int x)
{
    return x * 2;
}

int rs(const int x)
{
    return x * 2 + 1;
}

vector<pair<int, pii> > make;

struct info
{
    int mex, save_min;
    bool reverse, fill, erase;

    info()
    {
        mex = -1;
        save_min = -1;
        reverse = false;
        fill = false;
        erase = false;
    }
};

info operator+(const info &a, const info &b)
{
    info ans;
    if (a.mex == -1)
        ans.mex = b.mex;
    else if (b.mex == -1)
        ans.mex = a.mex;
    else
        ans.mex = min(a.mex, b.mex);
    if (a.save_min == -1)
        ans.save_min = b.save_min;
    else if (b.save_min == -1)
        ans.save_min = a.save_min;
    else
        ans.save_min = min(a.save_min, b.save_min);
    ans.reverse = false, ans.fill = false;
    ans.erase = false;
    return ans;
}

struct arrayDiscretization
{
    vector<int> array;

    arrayDiscretization()
    {
    }

    void push_back(const int i)
    {
        array.push_back(i);
    }

    void Discretization()
    {
        array.erase(unique(array.begin(), array.end()), array.end());
        sort(array.begin(), array.end());
    }

    int find(const int i) const
    {
        return lower_bound(array.begin(), array.end(), i) - array.begin();
    }

    int reverseFind(const int i) const
    {
        return array[i];
    }
};

arrayDiscretization dis;

void input()
{
    const int n = read();
    for (int i = 0; i < n; i++)
    {
        int x = read(), y = read(), z = read();
        dis.push_back(y);
        dis.push_back(z);
        make.push_back(make_pair(x, make_pair(y, z)));
    }
    dis.push_back(0);
    dis.Discretization();
}

info tree[maxn * 4];

void push_up(int root)
{
    tree[root] = tree[root * 2] + tree[root * 2 + 1];
}

void push_down(const int root, const int l, const int r)
{
    const int mid = l + (r - l) / 2;
    if (tree[root].fill)
    {
        tree[ls(root)].fill = true;
        tree[rs(root)].fill = true;
        tree[ls(root)].erase = false;
        tree[rs(root)].erase = false;
        tree[ls(root)].reverse = false;
        tree[rs(root)].reverse = false;
        tree[ls(root)].save_min=l;
        tree[rs(root)].save_min=mid+1;
        tree[ls(root)].mex=-1;
        tree[rs(root)].mex=-1;
    }
    if (tree[root].erase)
    {
        tree[ls(root)].fill = false;
        tree[rs(root)].fill = false;
        tree[ls(root)].erase = true;
        tree[rs(root)].erase = true;
        tree[ls(root)].reverse = false;
        tree[rs(root)].reverse = false;
        tree[ls(root)].save_min=-1;
        tree[rs(root)].save_min=-1;
        tree[ls(root)].mex=l;
        tree[rs(root)].mex=mid+1;
    }
    if (tree[root].reverse)
    {
        tree[ls(root)].reverse ^= 1;
        tree[rs(root)].reverse ^= 1;
        swap(tree[ls(root)].mex, tree[ls(root)].save_min);
        swap(tree[rs(root)].mex, tree[rs(root)].save_min);
    }
    return;
}

void build(const int root, const int l, const int r)
{
    if (l == r)
    {
        tree[root].mex = l;
        tree[root].reverse = false, tree[root].fill = false, tree[root].erase = false;
        return;
    }
    int mid = (l + r) / 2;
    build(ls(root), l, mid);
    build(rs(root), mid + 1, r);
    push_up(root);
}

void add(const int root, const int l, const int r, const int l1, const int r1)
{
    if (l1 == l && r == r1)
    {
        tree[root].mex = -1;
        tree[root].save_min = l;
        tree[root].fill = true;
        tree[root].erase = false;
        tree[root].reverse = false;
        return;
    }
    push_down(root,l1,r1);
    const int mid = (l1 + r1) / 2;
    if (r <= mid)
        add(ls(root), l, mid, l1, mid);
    else if (l > mid)
        add(rs(root), l, r, mid + 1, r1);
    else
    {
        add(ls(root), l, mid, l1, mid);
        add(rs(root), mid + 1, r, mid + 1, r1);
    }
    push_up(root);
}

void erase(const int root, const int l, const int r, const int l1, const int r1)
{
    if (l1 == l && r == r1)
    {
        tree[root].mex = l;
        tree[root].save_min = -1;
        tree[root].fill = false;
        tree[root].erase = true;
        tree[root].reverse = false;
        return;
    }
    push_down(root,l1,r1);
    const int mid = (l1 + r1) / 2;
    if (r <= mid)
        erase(ls(root), l, mid, l1, mid);
    else if (l > mid)
        erase(rs(root), l, r, mid + 1, r1);
    else
    {
        erase(ls(root), l, mid, l1, mid);
        erase(rs(root), mid + 1, r, mid + 1, r1);
    }
    push_up(root);
}

void reverse(const int root, const int l, const int r, const int l1, const int r1)
{
    if (l1 == l && r == r1)
    {
        swap(tree[root].mex, tree[root].save_min);
        tree[root].reverse ^= 1;
        return;
    }
    push_down(root,l1,r1);
    const int mid = (l1 + r1) / 2;
    if (r <= mid)
        reverse(ls(root), l, mid, l1, mid);
    else if (l > mid)
        reverse(rs(root), l, r, mid + 1, r1);
    else
    {
        reverse(ls(root), l, mid, l1, mid);
        reverse(rs(root), mid + 1, r, mid + 1, r1);
    }
    push_up(root);
}

info query(const int root, const int l, const int r, const int l1, const int r1)
{
    if (l1 == l && r == r1)
        return tree[root];
    push_down(root,l1,r1);
    const int mid = (l + r) / 2;
    if (r <= mid)
        return query(ls(root), l, mid, l1, mid);
    else if (l > mid)
        return query(rs(root), mid + 1, r, mid + 1, r1);
    else
        return query(ls(root), l, mid, l1, mid) + query(rs(root), mid + 1, r, mid + 1, r1);
}

void solve()
{
    input();
    build(1,1,dis.array.size());
    for (auto i : make)
    {
        if (i.first==1)
        {
            add(1,dis.find(i.second.first),dis.find(i.second.second),1,dis.array.size());

        }
        else if (i.first==2)
        {
            erase(1,dis.find(i.second.first),dis.find(i.second.second),1,dis.array.size());
        }
        else
        {
            reverse(1,dis.find(i.second.first),dis.find(i.second.second),1,dis.array.size());
        }
        info ans=query(1,1,dis.array.size(),1,dis.array.size());
        if (ans.mex!=-1)
            cout<<dis.reverseFind(ans.mex)<<endl;
        else
            cout<<*prev(dis.array.end())+1<<endl;
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
    //cin >> t;
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 2025/8/22.
//
