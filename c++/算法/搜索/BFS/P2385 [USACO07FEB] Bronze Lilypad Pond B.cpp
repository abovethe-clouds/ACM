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

void solve()
{
    int n, m, m1, m2;
    cin >> n >> m >> m1 >> m2;
    int dx[8] = {m1, m1, -m1, -m1, m2, m2, -m2, -m2};
    int dy[8] = {m2, -m2, m2, -m2, m1, -m1, m1, -m1};
    int mp[31][31] = {};
    int bx, by, ex, ey;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            if (a == 0 || a == 2)
            {
                mp[i][j] = -1;
            }
            else
            {
                if (a == 3)
                {
                    mp[i][j] = 0;
                    bx = i, by = j;
                }
                else if (a == 1)
                {
                    mp[i][j] = inf;
                }
                else
                {
                    mp[i][j] = inf;
                    ex = i, ey = j;
                }
            }
        }
    }
    queue<pii> q;
    q.push({bx, by});
    while (!q.empty())
    {
        pii b = q.front();
        q.pop();
        if (b.first == ex && b.second == ey)
        {
            cout << mp[b.first][b.second];
            return;
        }
        for (int i = 0; i < 8; i++)
        {
            int x1 = b.first + dx[i];
            int y1 = b.second + dy[i];
            if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && mp[x1][y1] == inf)
            {
                mp[x1][y1] = mp[b.first][b.second] + 1;
                q.push({x1, y1});
            }
        }
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