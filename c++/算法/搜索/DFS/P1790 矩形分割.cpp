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
int mp[501][501];
void solve()
{
    int n, m, a, c;
    cin >> n >> m >> a >> c;
    for (int i = 0; i < 501; i++)
    {
        for (int j = 0; j < 501; j++)
        {
            mp[i][j] = inf;
        }
    }
    queue<pii> q;
    for (int i = 0; i < a; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        mp[l][r] = 0;
        q.push({l, r});
    }
    while (!q.empty())
    {
        pii b = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
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
    for (int i = 0; i < c; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << mp[l][r] << endl;
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