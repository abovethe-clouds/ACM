#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 5e3 + 1;
int dp[maxn][maxn] = {};
string s;

int dfs(int l, int r)
{
    if (l > r) return dp[l][r] = 1;
    if (dp[l][r] != 0) return dp[l][r];
    if (l == r) return dp[l][r] = -1;
    int ans = -1;
    if (s[l - 1] == s[r - 1])
    {
        if (dfs(l + 1, r - 1) == 1)
            ans = 1;
    }
    if (ans == -1)
    {
        for (int i = l + 1; i < r; i++)
        {
            if (dfs(l, i) == 1 && dfs(i + 1, r) == 1)
            {
                ans = 1;
                break;
            }
        }
    }
    return dp[l][r] = ans;
}

void solve()
{
    int n;
    cin >> n;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty() || st.top() != s[i])
            st.push(s[i]);
        else
            st.pop();
    }
    if (st.empty())
    {
        cout << "YES\n";
        return;
    }
    // for (int i = 0; i <= n; i++)
    //     for (int j = 0; j <= n; j++)
    //         dp[i][j] = 0;
    // if (dfs(1, n) == 1)
    //     cout << "YES\n";
    else
        cout << "NO\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
