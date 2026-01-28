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
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 2e5 + 5;
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

int ls(int x)
{
    return x << 1;
}

int rs(int x)
{
    return x << 1 | 1;
}

struct seg_point
{
    vector<pii> data;

    seg_point()
    {
        data.resize(2);
    }

    explicit seg_point(int x)
    {
        data.resize(2);
        data[0] = {x, 1};
        data[1] = {inf, 0};
    }
};

vector<pii> BM_merge(vector<pii> a, const vector<pii> &b)
{
    for (const auto &pb : b)
    {
        if (pb.second <= 0) continue;

        pii p = pb;
        bool flag = false;
        for (int i = 0; i < 2; i++)
        {
            if (a[i].first == p.first)
            {
                a[i].second += p.second;
                flag = true;
                break;
            }
        }
        if (flag) continue;
        for (int i = 0; i < 2; i++)
        {
            if (a[i].second == 0)
            {
                a[i] = p;
                flag = true;
                break;
            }
        }
        if (flag) continue;
        int mn = p.second;
        for (int i = 0; i < 2; i++)
            if (a[i].second < mn) mn = a[i].second;
        for (int i = 0; i < 2; i++)
            a[i].second -= mn;
        p.second -= mn;
        for (int i = 0; i < 2; i++)
        {
            if (a[i].second == 0)
            {
                a[i] = p;
                break;
            }
        }
    }
    return a;
}


struct segment_tree
{
    vector<seg_point> tree;

    explicit segment_tree(int n)
    {
        tree.resize(4 * n + 5);
    }

    void push_up(int root)
    {
        tree[root] = merge(tree[ls(root)], tree[rs(root)]);
    }

    void built(vector<int> &v, int l, int r, int pos)
    {
        if (l == r)
        {
            tree[pos] = seg_point(v[l]);
            return;
        }
        int mid = (l + r) >> 1;
        built(v, l, mid, ls(pos));
        built(v, mid + 1, r, rs(pos));
        push_up(pos);
    }

    seg_point merge(const seg_point &a, const seg_point &b)
    {
        seg_point res;
        res.data = BM_merge(a.data, b.data);
        return res;
    }

    seg_point query(int L, int R, int l, int r, int pos)
    {
        if (L <= l && r <= R)
        {
            return tree[pos];
        }
        int mid = (l + r) >> 1;
        seg_point res;
        if (L <= mid)
        {
            res = merge(res, query(L, R, l, mid, ls(pos)));
        }
        if (R > mid)
        {
            res = merge(res, query(L, R, mid + 1, r, rs(pos)));
        }
        return res;
    }
};

void solve()
{
    int n = read(), q = read();
    vector<int> v(n + 1);
    vector<pii> where;
    for (int i = 1; i <= n; i++)
    {
        v[i] = read();
        where.push_back({v[i], i});
    }
    sort(where.begin(), where.end());
    segment_tree segt(n);
    segt.built(v, 1, n, 1);
    while (q--)
    {
        int l = read(), r = read();
        vector<int> ans;
        seg_point res = segt.query(l, r, 1, n, 1);
        if (res.data.empty())
        {
            cout << -1 << endl;
            continue;
        } else
        {
            for (const auto &p: res.data)
            {
                if (p.second<=0) continue;
                if (lower_bound(where.begin(), where.end(), make_pair(p.first, r+1)) -lower_bound(where.begin(), where.end(), make_pair(p.first, l )) >( (r - l + 1) / 3))
                    ans.push_back(p.first);
            }
        }
        if (ans.empty())
        {
            cout << -1 << endl;
            continue;
        }
        sort(ans.begin(), ans.end());
        for (const auto &x: ans)
            cout << x << " ";
        cout << endl;
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
    t=read();
    while (t--)
        solve();
    return 0;
}


/*
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
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=2e5;
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
vector<int> v(2e5);
struct problem
{
    int l,r,i;
};
set<int> have_num[maxn];
int cnt[maxn]={};
void add(int pos) {
    int val = v[pos];
    have_num[cnt[val]].erase(val);
    cnt[val]++;
    have_num[cnt[val]].insert(val);
}

void del(int pos) {
    int val = v[pos];
    have_num[cnt[val]].erase(val);
    cnt[val]--;
    have_num[cnt[val]].insert(val);
}

void solve()
{
    const int n = read(),q=read();
    for (int i = 0; i < n; i++) cnt[v[i]] = 0;
    for (int i = 0; i <= n; i++) have_num[i].clear();
    for(int i=0;i<n;i++)
        v[i]=read();
    vector<int> li = v;
    sort(li.begin(), li.end());
    li.erase(unique(li.begin(), li.end()), li.end());
    for (int i = 0; i < n; i++) {
        v[i] = lower_bound(li.begin(), li.end(), v[i]) - li.begin();
    }
    vector<problem> p(q);
    vector<int> ans[q];
    for(int i=0;i<q;i++)
    {
        p[i].l=read();
        p[i].r=read();
        p[i].l--;
        p[i].r--;
        p[i].i=i;
    }
    sort(p.begin(),p.end(),[=](problem p1,problem p2)
    {
        const int x=sqrt(n);
        if (p1.l/x!=p2.l/x)
            return p1.l<p2.l;
        else
            return p1.r<p2.r;
    }
        );
    int l=0,r=-1;
    for(int i=0;i<q;i++)
    {
        while(p[i].l<l) add(--l);
        while(p[i].r>r) add(++r);
        while(p[i].l>l) del(l++);
        while(p[i].r<r) del(r--);
        int c=0;
        for (auto ii=(r-l+1)/3+1;ii<=(r-l+1);ii++)
        {
            if (c>=2)
                break;
            if (have_num[ii].empty())
                continue;
            for (auto j:have_num[ii])
            {
                ans[p[i].i].push_back(j);
                c++;
            }
        }
    }
    for (int i=0;i<q;i++)
    {
        if (ans[i].empty())
            cout<<0<<endl;
        else
        {
            for (auto o:ans[i])
                cout<<li[o]<<" ";
            cout<<endl;
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
    t=read();
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2025/9/27.
//
*/






