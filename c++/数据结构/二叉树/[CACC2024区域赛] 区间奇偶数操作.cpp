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
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 5e5;
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

struct point
{
    int sum=0, oddCnt = 0, evenCnt = 0;
    int lazyOdd = 0, lazyEven = 0;
};

vector<point> tree;
vector<int> v;

void input()
{
    v.push_back(0);
    n = read(), m = read();
    for (int i = 0; i < n; i++)
        v.push_back(read());
    tree.resize(n * 4 + 20);
}

point new_point(int x)
{
    point ans;
    ans.sum = x;
    ans.oddCnt = (x % 2 == 1 ? 1 : 0);
    ans.evenCnt = ans.oddCnt ^ 1;
    ans.lazyOdd = 0;
    ans.lazyEven = 0;
    return ans;
}

point merge(point a, point b)
{
    point n = {};
    n.sum = a.sum + b.sum;
    n.oddCnt = a.oddCnt + b.oddCnt;
    n.evenCnt = a.evenCnt + b.evenCnt;
    n.lazyEven = 0, n.lazyOdd = 0;
    return n;
}

void push_up(int root)
{
    tree[root] = merge(tree[ls  (root)], tree[rs(root)]);
}

void built(int root,int l,int r)
{
    if (l == r)
    {
        tree[root].sum = v[l];
        return;
    }
    int mid = (l + r) >> 1;
    built(root * 2, l, mid);
    built(root * 2 + 1, mid + 1, r);
    push_up(root);
    return;
}

void push_down(int root)
{
    int l = ls(root), r = rs(root);
    // 推下 lazyEven（对当前为偶数的元素加值）
    if (tree[root].lazyEven != 0)
    {
        int add = tree[root].lazyEven;
        // 左子节点
        tree[l].sum += add * tree[l].evenCnt;
        if (add % 2 != 0)
        {
            tree[l].oddCnt += tree[l].evenCnt;
            tree[l].evenCnt = 0;
        }
        tree[l].lazyEven += add;
        // 右子节点
        tree[r].sum += add * tree[r].evenCnt;
        if (add % 2 != 0)
        {
            tree[r].oddCnt += tree[r].evenCnt;
            tree[r].evenCnt = 0;
        }
        tree[r].lazyEven += add;
        tree[root].lazyEven = 0;
    }
    // 推下 lazyOdd（对当前为奇数的元素加值）
    if (tree[root].lazyOdd != 0)
    {
        int add = tree[root].lazyOdd;
        // 左子节点
        tree[l].sum += add * tree[l].oddCnt;
        if (add % 2 != 0)
        {
            tree[l].evenCnt += tree[l].oddCnt;
            tree[l].oddCnt = 0;
        }
        tree[l].lazyOdd += add;
        // 右子节点
        tree[r].sum += add * tree[r].oddCnt;
        if (add % 2 != 0)
        {
            tree[r].evenCnt += tree[r].oddCnt;
            tree[r].oddCnt = 0;
        }
        tree[r].lazyOdd += add;
        tree[root].lazyOdd = 0;
    }
}
void updata(int root,int l,int r,int l1,int r1,int judge,int add) //前root范围，后updata范围
{
    if (tree[root].lazyEven != 0 || tree[root].lazyOdd != 0)
        push_down(root);
    auto &[sum,oddCnt,evenCnt,lazyOdd,lazyEven] = tree[root];
    if (l == l1 && r == r1)
    {
        if (judge == 0)
        {
            sum += add * evenCnt;
            if (add % 2 == 0)
            {
                lazyEven += add;
            }
            else
            {
                oddCnt += evenCnt;
                evenCnt = 0;
                lazyEven += add;
            }
        }
        else
        {
            sum += add * oddCnt;
            if (add % 2 == 0)
            {
                lazyOdd += add;
            }
            else
            {
                evenCnt += oddCnt;
                oddCnt = 0;
                lazyOdd += add;
            }
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (r <= mid)
        updata(ls(root), l, mid, l1, r1, judge, add);
    else if (l > mid)
        updata(rs(root), mid + 1, r, l1, r1, judge, add);
    else
    {
        updata(ls(root), l, mid, l1, mid, judge, add);
        updata(rs(root), mid + 1, r, mid + 1, r1, judge, add);
    }
    push_up(root);
}

point query(int root,int l,int r,int l1,int r1) //前root范围，后query范围
{
    if (tree[root].lazyEven != 0 || tree[root].lazyOdd != 0)
        push_down(root);
    if (l == l1 && r == r1)
        return tree[root];
    int mid = (l + r) >> 1;
    if (r <= mid)
        return query(ls(root), l, mid, l1, r1);
    else if (l > mid)
        return query(rs(root), mid + 1, r, l1, r1);
    else
        return merge(query(ls(root), l, mid, l1, mid), query(rs(root), mid + 1, r, mid + 1, r1));
}

void solve()
{
    input();
    while (m--)
    {
        int op = read();
        if (op == 0)
        {
            int l = read(), r = read(), judge = read(), add = read();
            updata(1, 1, n, l, r, judge, add);
        }
        else
        {
            int l = read(), r = read();
            cout << query(1, 1, n, l, r).sum << endl;
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
    //t=read();
    while (t--)
        solve();
    return 0;
}
