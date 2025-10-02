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
struct point
{
    int x, y, x_num, y_num;

    friend point operator+(point &a, point &b)
    {
        point res = {-1, -1, 0, 0};
        if (a.x != -1)
        {
            res.x = a.x;
            res.x_num = a.x_num;
        }
        if (a.y != -1)
        {
            res.y = a.y;
            res.y_num = a.y_num;
        }
    }
}

point tree[4 * maxn];
int v[maxn];
int ls(int x)
{
    return x << 1;
}

int rs(int x)
{
    return x << 1 | 1;
}

void push_up(int root)
{

}

void build(int root,int l,int r)
{
    if (l == r)
    {
        tree[root].x = v[l];
        tree[root].y = -inf;
        tree[root].x_num = 1;
        tree[root].y_num = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(root<<1, l, mid);
    build(root<<1 | 1, mid + 1, r);
}
void solve()
{
    int n = read(),q=read();
    for (int i=1;i<n;i++)
        
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

