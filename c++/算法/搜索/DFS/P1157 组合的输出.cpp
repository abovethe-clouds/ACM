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
int n, m;
bool judge[25] = {};
int a[25] = {};
void dfs(int x)
{
    if (x == m + 1)
    {
        for (int i = 1; i <= m; i++)
        {
            cout << setw(3) << a[i];
        }
        cout << endl;
        return;
    }
    for (int i = a[x - 1] + 1; i <= n; i++)
    {
        if (!judge[i])
        {
            a[x] = i;
            judge[i] = 1;
            dfs(x + 1);
            judge[i] = 0;
        }
    }
    return;
}
void solve()
{
    cin >> n >> m;
    dfs(1);
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