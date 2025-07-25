#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 1e3 + 5;
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
int n, m, k;
struct edge
{
    int l, e1, e2;
    bool operator<(const edge &q) const
    {
        return l > q.l;
    }
};
int f[maxn];
int find(int x)
{
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
void add(int x, int y)
{
    f[find(f[x])] = find(f[y]);
    return;
}
priority_queue<edge> q;
void solve()
{
    cin >> n >> m >> k;
    int cnt = 0, sum = 0;
    for (int i = 0; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        edge xx;
        cin >> xx.e1 >> xx.e2 >> xx.l;
        q.push(xx);
    }
    while (!q.empty() && cnt != n - k)
    {
        edge neww = q.top();
        q.pop();
        if (find(neww.e1) == find(neww.e2))
            continue;
        sum += neww.l;
        cnt++;
        add(neww.e1, neww.e2);
    }
    if (cnt == n - k)
        cout << sum << endl;
    else
        cout << "No Answer" << endl;
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