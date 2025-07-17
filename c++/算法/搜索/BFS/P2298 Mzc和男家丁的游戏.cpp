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
int vis[2001][2001];
char mp[2001][2001];
void solve()
{
    int n, m, bx, by;
    cin >> n >> m;
    queue<pii> q;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '.')
            {
                mp[i][j] = 0;
                vis[i][j] = inf;
            }
            else
            {
                if (s[j] == 'd')
                {
                    mp[i][j] = 2;
                    vis[i][j] = inf;
                }
                else if (s[j] == '#')
                {
                    mp[i][j] = 1;
                    vis[i][j] = -1;
                }
                else
                {
                    mp[i][j] = 0;
                    vis[i][j] = 0;
                    bx = i, by = j;
                }
            }
        }
    }
    q.push({bx, by});
    while (!q.empty())
    {
        pii b = q.front();
        if (mp[b.first][b.second] == 2)
        {
            cout << vis[b.first][b.second];
            return;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = b.first + dx[i];
            int y1 = b.second + dy[i];
            if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && vis[x1][y1] == inf)
            {
                vis[x1][y1] = vis[b.first][b.second] + 1;
                q.push({x1, y1});
            }
        }
    }
    cout << "No Way!" << endl;
    return;
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