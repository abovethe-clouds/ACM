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
bool in(int x1, int y1, int x2, int y2, int px, int py)
{
    int minx = min(x1, x2), maxx = max(x1, x2);
    int miny = min(y1, y2), maxy = max(y1, y2);
    return px >= minx && px <= maxx && py >= miny && py <= maxy;
}
int X(int x1, int y1, int x2, int y2)
{
    return x1 * y2 - x2 * y1;
}
void solve()
{
    int x[4], y[4];
    for (int i = 0; i < 4; i++)
    {
        char ch;
        cin >> ch >> x[i] >> ch >> y[i] >> ch;
    }

    if ((y[3] == y[0] && x[3] == x[0]) || (y[3] == y[1] && x[3] == x[1]) || (y[3] == y[2] && x[3] == x[2]))
    {
        cout << 4;
        return;
    }

    int ABx = x[1] - x[0], ABy = y[1] - y[0], BCx = x[2] - x[1], BCy = y[2] - y[1], CAx = x[0] - x[2], CAy = y[0] - y[2];
    int APx = x[3] - x[0], APy = y[3] - y[0], BPx = x[3] - x[1], BPy = y[3] - y[1], CPx = x[3] - x[2], CPy = y[3] - y[2];
    int x1 = X(ABx, ABy, APx, APy);
    int x2 = X(BCx, BCy, BPx, BPy);
    int x3 = X(CAx, CAy, CPx, CPy);
    if ((x1 > 0 && x2 > 0 && x3 > 0) || (x1 < 0 && x2 < 0 && x3 < 0))
    {
        cout << 1;
        return;
    }

    if ((x1 == 0 && in(x[0], y[0], x[1], y[1], x[3], y[3])) || (x2 == 0 && in(x[1], y[1], x[2], y[2], x[3], y[3])) || (x3 == 0 && in(x[2], y[2], x[0], y[0], x[3], y[3])))
    {
        cout << 3;
        return;
    }
    cout << 2;
}
int main()
{
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
// cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // reopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}