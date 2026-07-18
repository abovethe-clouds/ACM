#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second

typedef long long ll;
#define int long long
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;

void solve()
{
    int n;
    cin>>n;
    vector<vector<bool> > mp(n + 1, vector<bool>(n + 1, false));
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            mp[i][j + 1] = s[j] == '1';
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!mp[i][i])
        {
            cout << "NO\n";
            return;
        }
        for (int j = 1; j <= n; j++)
        {
            if (i != j && mp[i][j] && mp[j][i])
            {
                cout << "NO\n";
                return;
            }
        }
    }
    vector<int> sz(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mp[i][j])
            {
                sz[i]++;
            }
        }
    }
    vector<int> id(n);
    for (int i = 0; i < n; i++)
    {
        id[i] = i + 1;
    }

    sort(id.begin(), id.end(), [&](int a, int b)
    {
        return sz[a] > sz[b];
    });

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
    cin>>t;
    while (t--)
        solve();
    return 0;
}

//
// Created by Administrator on 2026/3/19.
//
