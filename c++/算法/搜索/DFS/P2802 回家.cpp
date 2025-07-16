#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
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
int mp[10][10] = {};
struct point
{
    int x, y, z, b;
};
void solve()
{
    int n, m, bx, by, ex, ey;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 2)
                bx = i, by = j;
            if (mp[i][j] == 3)
                ex = i, ey = j;
        }
    }
    int z[10][10][7];
    for (auto &ii : z)
        for (auto &iii : ii)
            for (auto &iiii : iii)
                iiii = inf;
    point ooo = {bx, by, 6, 0};
    queue<point> q;
    q.push(ooo);
    while (!q.empty())
    {
        point b = q.front();
        q.pop();
        if (b.z == 0)
            continue;
        if (mp[b.x][b.y] == 4)
            b.z = 6;
        z[b.x][b.y][b.z] = min(b.b, z[b.x][b.y][b.z]);
        for (int i = 0; i < 4; i++)
        {
            int x1 = b.x + dx[i];
            int y1 = b.y + dy[i];
            int b1 = b.b + 1;
            int z1 = b.z - 1;
            if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < m && mp[x1][y1] != 0 && z[x1][y1][z1] == inf)
            {
                q.push({x1, y1, z1, b1});
                z[x1][y1][z1] = b1;
            }
        }
    }
    int minn = inf + 1;
    for (int i = 1; i < 7; i++)
    {
        minn = min(z[ex][ey][i], minn);
    }
    if (minn == inf)
        cout << -1;
    else
        cout << minn;
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