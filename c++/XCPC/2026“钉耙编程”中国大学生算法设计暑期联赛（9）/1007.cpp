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
const int mod1 = 1e9 + 7, mod2 = 998244353, inf = 0x3f3f3f3f, P = 131;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
pii rand_pii()
{
    return {rng() % mod1, rng() % mod2};
}
map<pii, pii> mp1,mp;
int n, q, k;
pii get1(int i,int kk)
{
    if (kk==0||kk==k)
        return {0, 0};
    if (mp1.count({i, kk}))
        return mp1[{i, kk}];
    return mp1[{i, kk}] =rand_pii();
}
pii get(int i,int kk)
{
    auto ans=[](pii x,pii y){
        return make_pair((y.first-x.first+mod1) % mod1,(y.second-x.second+mod2) % mod2);
    };
    return ans(get1(i, kk), get1(i, kk + 1));
}
pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b)
{
    return {(a.first + b.first) % mod1, (a.second + b.second) % mod2};
}
template<typename T>
struct seg_tree
{
    vector<T> tree;
    seg_tree (vector<T> &arr)
    {
        int n = arr.size();
        tree.resize(4 * n, {0, 0});
        build(arr, 1, 1, n-1);
    }
    void up(int node)
    {
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void build(vector<T> &arr, int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = arr[start];
        }
        else
        {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            up(node);
        }
    }
    void update(int node, int start, int end, int idx, T val)
    {
        if (start == end)
        {
            tree[node] = val;
        }
        else
        {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid)
            {
                update(2 * node, start, mid, idx, val);
            }
            else
            {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            up(node);
        }
    }
    T query(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
        {
            return {0, 0};
        }
        if (l <= start && end <= r)
        {
            return tree[node];
        }
        int mid = (start + end) / 2;
        T p1 = query(2 * node, start, mid, l, r);
        T p2 = query(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }
};
void solve()
{
    mp1.clear();
    mp.clear();
    cin >> n >> q >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    vector<pii> v(n+1);
    for (int i = 1; i <= n; i++)
    {
        v[i] = get(a[i], b[i]);
    }
    seg_tree<pii> st(v);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int p,x,c;
            cin>> p >> x >> c;
            st.update(1, 1, n, p, get(x, c));
        }
        else
        {
            int l,r;
            cin >> l >> r;
            pii ans = st.query(1, 1, n, l, r);
            if (ans.first == 0 && ans.second == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
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
// Created by Administrator on 2026/8/19.
//
