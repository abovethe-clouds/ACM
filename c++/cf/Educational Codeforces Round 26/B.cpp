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

void solve()
{
    int n, m;
    cin >> n >> m;
    char mp[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
            mp[i][j] = s[j - 1];
    }
    if (n % 3 == 0)
    {
        map<char, bool> judge;
        bool flag = true;
        for (int i = 1; i <= n / 3; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (mp[i][j] != mp[1][1])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        judge[mp[1][1]] = true;
        if (flag)
        {
            if (judge[mp[n / 3 + 1][1]]) flag = false;
            judge[mp[n / 3 + 1][1]] = true;
            for (int i = n / 3 + 1; i <= n - (n / 3); i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (mp[i][j] != mp[n / 3 + 1][1])
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
        }
        if (flag)
        {
            if (judge[mp[n - (n / 3) + 1][1]]) flag = false;
            for (int i = n - (n / 3) + 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (mp[i][j] != mp[n - (n / 3) + 1][1])
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
            return;
        }
    }
    if (m % 3 == 0)
    {
        map<char, bool> judge;
        bool flag = true;
        for (int i = 1; i <= m / 3; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (mp[j][i] != mp[1][1])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        judge[mp[1][1]] = true;
        if (flag)
        {
            if (judge[mp[1][m / 3 + 1]]) flag = false;
            judge[mp[1][m / 3 + 1]] = true;
            for (int i = m / 3 + 1; i <= m - (m / 3); i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (mp[j][i] != mp[1][m / 3 + 1])
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
        }
        if (flag)
        {
            if (judge[mp[1][m - (m / 3) + 1]]) flag = false;
            for (int i = m - (m / 3) + 1; i <= m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (mp[j][i] != mp[1][m - (m / 3) + 1])
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
