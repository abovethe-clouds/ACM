#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
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

int a[20] = {};
int f[20][200];

int dfs(int x, int sum, bool top)
{
    if (x == 0) return sum;
    if (!top && f[x][sum] >= 0) return f[x][sum];
    int num_top = top ? a[x] : 9;
    int ans = 0;
    for (int i = 0; i <= num_top; i++)
    {
        ans = (ans + dfs(x - 1, sum + i, top && (i == num_top))) % mod;
    }
    if (!top) f[x][sum] = ans;
    return ans;
}

int make(int n)
{
    int ans = 0;
    while (n)
    {
        a[++ans] = n % 10;
        n /= 10;
    }
    return dfs(ans, 0, 1) % mod;
}

void solve()
{
    ll l, r;
    cin >> l >> r;
    cout << (make(r) - make(l - 1) + mod) % mod << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        memset(f, -1, sizeof(f));
        solve();
    }
    return 0;
}
