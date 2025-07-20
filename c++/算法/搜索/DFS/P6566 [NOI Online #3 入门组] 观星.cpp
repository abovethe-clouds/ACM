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
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1}, dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int n, m;
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
bool mp[1501][1501] = {};
int cnt = 0;
map<int, int> _x;
void dfs(int x, int y)
{
    cnt++;
    mp[x][y] = 1;
    for (int i = 0; i < 8; i++)
    {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if (x1 < n && x1 >= 0 && y1 < m && y1 >= 0 && mp[x1][y1] == 0)
        {
            dfs(x1, y1);
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            if (ch == '.')
                mp[i][j] = 1;
            else
                mp[i][j] = 0;
        }
    }
    int cnt_xinxi = 0, maxn = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == 0)
            {
                dfs(i, j);
                if (_x[cnt] == 0)
                    cnt_xinxi++;
                _x[cnt]++;
                maxn = max(_x[cnt] * cnt, maxn);
                cnt = 0;
            }
        }
    }
    cout << cnt_xinxi << " " << maxn;
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