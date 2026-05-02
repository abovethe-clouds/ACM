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
    int C = 0, U = 0, D = 0, L = 0, R = 0, _ = 0;
    int n, m;
    cin >> n >> m;
    vector mp(n, vector<char>(m));
    vector vis(n, vector(m, false));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            mp[i][j] = s[j];
            switch (s[j])
            {
            case 'C': C++;
                break;
            case 'U': U++;
                break;
            case 'D': D++;
                break;
            case 'L': L++;
                break;
            case 'R': R++;
                break;
            default: _++;
                break;
            }
        }
    }
    if (_ != 1 || U + D + L + R != C * 2)
    {
        cout << "No" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == 'C')
            {
                int vertical = 0, horizontal = 0;
                C--;
                if (i - 1 >= 0 && mp[i - 1][j] == 'D' && !vis[i - 1][j])
                {
                    D--;
                    vertical++;
                    vis[i - 1][j] = true;
                }
                if (i + 1 < n && mp[i + 1][j] == 'U' && !vis[i + 1][j])
                {
                    U--;
                    vertical++;
                    vis[i + 1][j] = true;
                }
                if (j - 1 >= 0 && mp[i][j - 1] == 'R' && !vis[i][j - 1])
                {
                    R--;
                    horizontal++;
                    vis[i][j - 1] = true;
                }
                if (j + 1 < m && mp[i][j + 1] == 'L' && !vis[i][j + 1])
                {
                    L--;
                    horizontal++;
                    vis[i][j + 1] = true;
                }
                if (vertical != 1 || horizontal != 1)
                {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    if (C == 0 && U == 0 && D == 0 && L == 0 && R == 0 && mp[0][m - 1] == '.')
    {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
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

//
// Created by Administrator on 2026/4/29.
//
