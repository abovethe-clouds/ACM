#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn=2e5+5;
#define int ll
int n,m;
struct  point
{
    int num_1,num_0,first_num,first_long,end_num,end_long,long_num_1,long_num_0,tag=-1,tag_re=0;
    point operator+(point o)const
    {
        point n;
        if(end_num==o.first_num)
        {
            int maybelong = end_long + o.first_long;
            if(end_num==1)
            {
                n.long_num_1 = max(max(long_num_1, o.long_num_1), maybelong);
                n.long_num_0 = max(long_num_0, o.long_num_0);
            }
            else
            {
                n.long_num_0 = max(max(long_num_0, o.long_num_0), maybelong);
                n.long_num_1 = max(long_num_1, o.long_num_1);
            }
        }
        else
        {
            n.long_num_1 = max(long_num_1, o.long_num_1);
            n.long_num_0 = max(long_num_0, o.long_num_0);
        }
        n.num_0 = num_0 + o.num_0;
        n.num_1 = num_1 + o.num_1;
        n.first_num = first_num;
        n.end_num = o.end_num;
        if (first_long == (num_0 + num_1) && first_num == o.first_num)
            n.first_long = first_long + o.first_long;
        else
            n.first_long = first_long;
        if (o.end_long == (o.num_0 + o.num_1) && end_num == o.end_num)
            n.end_long = end_long + o.end_long;
        else
            n.end_long = o.end_long;
        n.tag = -1, n.tag_re = 0;
        return n;
    }
};
point tree[maxn*4];
int v[maxn];
int ls(int x) { return x*2; }
int rs(int x) { return x*2+1; }
void push_up(int x) { tree[x] = tree[ls(x)] + tree[rs(x)]; }
void point_change(int root, int l, int r, int c) {
    tree[root].end_long = tree[root].first_long = r - l + 1;
    tree[root].end_num = tree[root].first_num = c;
    tree[root].num_1 = (c == 1) ? (r - l + 1) : 0;
    tree[root].num_0 = (c == 0) ? (r - l + 1) : 0;
    tree[root].long_num_1 = (c == 1) ? (r - l + 1) : 0;
    tree[root].long_num_0 = (c == 0) ? (r - l + 1) : 0;
    tree[root].tag = c;
    tree[root].tag_re = 0;
}
void point_re(int root) {
    swap(tree[root].num_0, tree[root].num_1);
    swap(tree[root].long_num_1, tree[root].long_num_0);
    tree[root].first_num ^= 1;
    tree[root].end_num ^= 1;
    tree[root].tag_re ^= 1;
}
void push_down(int root, int l, int r) {
    int mid = (l + r) / 2;
    if (tree[root].tag != -1) {
        point_change(ls(root), l, mid, tree[root].tag);
        point_change(rs(root), mid+1, r, tree[root].tag);
        tree[root].tag = -1;
    }
    if (tree[root].tag_re) {
        point_re(ls(root));
        point_re(rs(root));
        tree[root].tag_re = 0;
    }
}
void built(int root, int l, int r) {
    if (l == r) {
        point_change(root, l, r, v[l]);
        return;
    }
    int mid = (l + r) / 2;
    built(ls(root), l, mid);
    built(rs(root), mid+1, r);
    push_up(root);
}
void chang(int root, int cl, int cr, int l, int r, int c) {
    if (cr < l || cl > r) return;
    if (cl >= l && cr <= r) {
        point_change(root, cl, cr, c);
        return;
    }
    push_down(root, cl, cr);
    int mid = (cl + cr) / 2;
    chang(ls(root), cl, mid, l, r, c);
    chang(rs(root), mid+1, cr, l, r, c);
    push_up(root);
}
void reverse(int root, int cl, int cr, int l, int r) {
    if (cr < l || cl > r) return;
    if (cl >= l && cr <= r) {
        point_re(root);
        return;
    }
    push_down(root, cl, cr);
    int mid = (cl + cr) / 2;
    reverse(ls(root), cl, mid, l, r);
    reverse(rs(root), mid+1, cr, l, r);
    push_up(root);
}
point find(int root, int cl, int cr, int l, int r) {
    if (cl >= l && cr <= r) return tree[root];
    push_down(root, cl, cr);
    int mid = (cl + cr) / 2;
    if (r <= mid) return find(ls(root), cl, mid, l, r);
    if (l > mid) return find(rs(root), mid+1, cr, l, r);
    return find(ls(root), cl, mid, l, mid) + find(rs(root), mid+1, cr, mid+1, r);
}
void scan() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i];
}
void solve() {
    scan();
    built(1, 1, n);
    while (m--) {
        int op, l, r;
        cin >> op >> l >> r;
        l++, r++;
        switch (op) {
            case 0: chang(1, 1, n, l, r, 0); break;
            case 1: chang(1, 1, n, l, r, 1); break;
            case 2: reverse(1, 1, n, l, r); break;
            case 3: cout << find(1, 1, n, l, r).num_1 << endl; break;
            case 4: cout << find(1, 1, n, l, r).long_num_1 << endl; break;
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}