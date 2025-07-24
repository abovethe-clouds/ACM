#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 5e4 + 5;
vector<int> mp[maxn];
int deep[maxn], st[maxn][21], point[maxn], maxx = 0;
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
void dfs_LCA(int b, int f)
{
    st[b][0] = f;
    deep[b] = deep[f] + 1;
    for (int i = 1; 1 << i <= deep[b]; i++)
    {
        st[b][i] = st[st[b][i - 1]][i - 1];
    }
    for (auto i : mp[b])
    {
        if (i != f)
            dfs_LCA(i, b);
    }
    return;
}
int LCA(int x, int y)
{
    if (x == y)
        return x;
    if (deep[x] < deep[y])
        swap(x, y);
    int dif = deep[x] - deep[y];
    for (int i = 20; i >= 0; i--)
    {
        if (1 << i <= dif)
        {
            dif -= (1 << i);
            x = st[x][i];
        }
    }
    if (x == y)
        return x;
    for (int i = 20; i >= 0; i--)
    {
        if (st[x][i] != st[y][i])
        {
            x = st[x][i];
            y = st[y][i];
        }
    }
    return st[x][0];
}
void change(int x, int y, int change)
{
    int lca = LCA(x, y);
    point[x] += change;
    point[y] += change;
    point[lca] -= change;
    point[st[lca][0]] -= change;
    return;
}
void dfs_sum(int b, int f)
{
    for (auto i : mp[b])
    {
        if (i != f)
            dfs_sum(i, b);
    }
    for (auto i : mp[b])
    {
        if (i != f)
            point[b] += point[i];
    }
    maxx = max(maxx, point[b]);
    return;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    deep[0] = -1;
    dfs_LCA(1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        change(a, b, 1);
    }
    dfs_sum(1, 0);
    cout << maxx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}