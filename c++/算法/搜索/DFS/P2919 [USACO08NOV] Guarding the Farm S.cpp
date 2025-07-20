#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
struct point
{
    int x, y, h;
};
bool cmp(point x, point y)
{
    return x.h > y.h;
}
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
int n, m;
bool vis[701][701];
int mp[701][701];
point so[701 * 701] = {};
void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
        int _x = x + dx[i], _y = y + dy[i];
        if (_x >= 0 && _x < n && _y >= 0 && y < m && vis[_x][_y] == 0 && mp[_x][_y] <= mp[x][y])
            dfs(_x, _y);
    }
    return;
}
void solve()
{
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            so[cnt++] = {i, j, mp[i][j]};
        }
    }
    sort(so, so + cnt, cmp);
    cnt = 0;
    for (auto i : so)
    {
        int x = i.x,
            y = i.y;
        if (!vis[x][y])
        {
            cnt++;
            dfs(x, y);
        }
    }
    cout << cnt;
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