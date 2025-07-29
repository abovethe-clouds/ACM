#include<bits/stdc++.h>
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
        if (ch == '-') w = -1;
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
int a[21], ans = 0;
bool check[21] = {};

void dp()
{
    bool sur[20000] = {};
    sur[0] = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (check[i] == 1)
            continue;
        for (int j = 20000; j >= 0; j--)
        {
            if (j - a[i] >= 0 && sur[j - a[i]] == 1)
            {
                sur[j] = true;
            }
        }
    }
    for (int i = 1; i < 20000; i++)
        if (sur[i]) sum++;
    ans = max(ans, sum);
}

void dfs(int i, int j)
{
    if (j > m) return;
    if (i == n)
    {
        if (j == m)
            dp();
        return;
    }
    dfs(i + 1, j);
    check[i] = true;
    dfs(i + 1, j + 1);
    check[i] = false;
}

void solve()
{
    n = read();
    m = read();
    for (int i = 0; i < n; i++)
    {
        a[i] = read();
    }
    dfs(0, 0);
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
