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
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
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
int W, H, K;
void solve()
{
    cin >> H >> W >> K;
    bool mp[H + 1][W + 1] = {};

    queue<pii> q;
    for (int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a][b] = 1;
    }
    pii s = {1, 1};
    mp[1][1] = 1;
    q.push(s);
    while (!q.empty())
    {
        pii f = q.front();
        int x = f.first, y = f.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (x1 > 0 && x1 <= H && y1 > 0 && y1 <= W && mp[x1][y1] == 0)
            {
                mp[x1][y1] = 1;
                q.push({x1, y1});
            }
        }
    }
    if (mp[H][W])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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