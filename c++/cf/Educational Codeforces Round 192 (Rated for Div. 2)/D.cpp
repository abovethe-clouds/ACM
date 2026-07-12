#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int long long
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> v1, v2;
    v1.push_back(0);
    v2.push_back(0);
    for (int i = 0; i < s1.size(); i++)
    {
        v1.push_back((s1[i] - '0' + v1.back()) % 10);
    }
    for (int i = 0; i < s2.size(); i++)
    {
        v2.push_back((s2[i] - '0' + v2.back()) % 10);
    }
    vector<vector<int>> dp(v1.size(), vector<int>(v2.size(), 0));
    if (v1.back()!=v2.back())
    {
        cout<<-1<<endl;
        return;
    }
    for (int i = 1; i < v1.size(); i++)
    {
        for (int j = 1; j < v2.size(); j++)
        {
            if (v1[i] == v2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[v1.size() - 1][v2.size() - 1] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
