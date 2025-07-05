#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 2e5 + 5;
#define int ll
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

int n, l, r, dp[maxn], a[maxn];
struct MonotonicQueue
{
    pii mp[maxn] = {};
    int head = 0, end = 0;
    bool is_min = 1;
    MonotonicQueue(bool min_mode = true) : is_min(min_mode) {};
    void push(pii x)
    {
        if (end - head == 0)
            mp[end++] = x;
        else
        {
            while (((x.second >= mp[end - 1].second && !is_min) || (x.second <= mp[end - 1].second && is_min)) && (end - head) != 0)
                end--;
            mp[end++] = x;
        }
    }
    void giveUp(pii x)
    {
        if (mp[head] == x)
            head++;
        return;
    }
    int find()
    {
        if (end - head != 0)
            return mp[head].second;
        else
            return INT_MIN;
    }
};
void solve()
{
    MonotonicQueue q(0);
    cin >> n >> l >> r;
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < l; i++)
    {
        dp[i] = -inf;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i - l >= 0)
            q.push({i - l, dp[i - l]});
        if (i - r - 1 >= 0)
            q.giveUp({i - r - 1, dp[i - r - 1]});
        int b = q.find();
        if (b == INT_MIN)
            dp[i] = -inf;
        else
            dp[i] = b + a[i];
    }
    int ans = -inf;
    for (int i = n - r + 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}