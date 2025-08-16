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
int l,r,dp[32][2][32][2];
bool is(int x)
{
    int i = 0, j = 0;
    while (x)
    {
        i += (x % 2 == 0);
        j++;
        x >>= 1;
    }
    return i * 2 >= j;
}

int ws(int x)
{
    int j = 0;
    while (x)
    {
        j++;
        x >>= 1;
    }
    return j;
}

int dfs(int x, int w, bool free, int i, int ff)
{
    if (w == 0)return 1;
    if (w == i)return 1;
    if (w < i)return 0;
    if (i == 0)
    {
        if (free)
        {
            dp[w][free][i][ff] = (1 << w);
            return dp[w][free][i][ff];
        } else
        {
            return (x & ((1 << w) - 1)) + 1;
        }
    }
    if (dp[w][free][i][ff])return dp[w][free][i][ff];
    int c = 0;
    int d = ff ? (i - 1) : w / 2;
    if (free)
    {
        c += dfs(x, w - 1, 1, d, ff) + dfs(x, w - 1, 1, i, 1);
    } else
    {
        if (x & (1 << (w - 1)))c += dfs(x, w - 1, 0, i, 1) + dfs(x, w - 1, 1, d, ff);
        else c += dfs(x, w - 1, 0, i - 1, ff);
    }
    dp[w][free][i][ff] = c;
    //cout<<x<<" "<<w<<" "<<free<<" "<<i<<" "<<c<<" "<<ff<<endl;
    return c;
}

void solve()
{
    cin >> l >> r;
    int l1 = ws(l), l2 = ws(r);
    int ans1 = dfs(r, l2, 0, (l2 + 1) / 2, 0);
    memset(dp, 0, sizeof(dp));
    int ans2 = dfs(l, l1, 0, (l1 + 1) / 2, 0);
    cout << ans1 - ans2 + is(l);
    return ;
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
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
