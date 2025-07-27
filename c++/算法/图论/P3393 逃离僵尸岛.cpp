#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7, inf = LONG_LONG_MAX, P = 131, maxn = 1e5 + 5;

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
int n, m, k, s, p, q;
bool is_z[maxn];
bool is_zz[maxn];
vector<int> mp[maxn];
bool vis_dij[maxn];
queue<pii> bfs_q;
int l[maxn];
void bfs()
{
    while (!bfs_q.empty())
    {
        pii f = bfs_q.front();

        bfs_q.pop();
        if (f.second >= s)
            continue;
        for (auto i : mp[f.first])
        {
            if (is_z[i])
                continue;
            is_z[i] = 1;
            bfs_q.push({i, f.second + 1});
        }
    }
}
void dij()
{
    for (int i = 0; i < maxn; i++)
        l[i] = inf;
    priority_queue<pii, vector<pii>, greater<pii>> q_dij;
    l[1] = 0;
    q_dij.push({l[1], 1});
    while (!q_dij.empty())
    {
        pii f = q_dij.top();
        q_dij.pop();
        if (vis_dij[f.second])
            continue;
        vis_dij[f.second] = 1;
        for (auto i : mp[f.second])
        {
            if (is_zz[i])
            {
                continue;
            }
            int l_ = 0;
            if (i != n)
            {
                if (is_z[i])
                    l_ = q;
                else
                    l_ = p;
            }
            if (l[i] > l[f.second] + l_)
            {
                l[i] = l[f.second] + l_;
                q_dij.push({l[i], i});
            }
        }
    }
}
void solve()
{

    cin >> n >> m >> k >> s >> p >> q;

    for (int i = 0; i < k; i++)
    {
        int b;
        cin >> b;
        bfs_q.push({b, 0});
        is_z[b] = 1;
        is_zz[b] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    bfs();
    dij();
    cout << l[n];
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