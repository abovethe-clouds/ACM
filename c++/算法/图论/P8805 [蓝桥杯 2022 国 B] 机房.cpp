#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 1e5 + 5;

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
vector<int> mp[maxn];
int point[maxn], sum[maxn], st[maxn][20], deep[maxn];
void dfs_LCA(int s, int f)
{
    st[s][0] = f;
    deep[s] = deep[f] + 1;
    for (int i = 1; 1 << i <= deep[s]; i++)
    {
        st[s][i] = st[st[s][i - 1]][i - 1];
    }
    point[s] = mp[s].size();
    sum[s] = sum[f] + point[s];
    for (auto i : mp[s])
    {
        if (i != f)
            dfs_LCA(i, s);
    }
}
int LCA(int x, int y)
{
    if (x == y)
        return x;
    if (deep[y] > deep[x])
        swap(x, y);
    int dif = deep[x] - deep[y];
    for (int i = 19; i >= 0; i--)
    {
        if (1 << i <= dif)
        {
            dif -= (1 << i);
            x = st[x][i];
        }
    }
    if (x == y)
        return x;
    for (int i = 19; i >= 0; i--)
    {
        if (st[x][i] != st[y][i])
        {
            x = st[x][i];
            y = st[y][i];
        }
    }
    return st[x][0];
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
    dfs_LCA(1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        int lca = LCA(a, b);
        int ans = sum[a] + sum[b] - 2 * sum[lca] + point[lca];
        cout << ans << endl;
    }
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