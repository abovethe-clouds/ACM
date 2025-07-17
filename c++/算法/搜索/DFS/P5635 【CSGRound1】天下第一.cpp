#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int mod, inf = 0x3f3f3f3f, P = 131;
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
char mp[10001][10001];
int dfs(int x, int y)
{
    if (mp[x][y] != 0)
        return mp[x][y];
    if (x == 0)
        return mp[x][y] = 1;
    if (y == 0)
        return mp[x][y] = 2;
    mp[x][y] = 4;
    int x1 = x, y1 = y;
    x = (x + y) % mod;
    y = (x + y) % mod;
    return mp[x1][y1] = dfs(x, y);
}
void solve()
{
    int a, b;
    cin >> a >> b;
    int ans = dfs(a, b);
    if (ans == 1)
    {
        cout << 1 << endl;
    }
    else if (ans == 2)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << "error" << endl;
    }
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
    cin >> t >> mod;
    while (t--)
        solve();

    return 0;
}