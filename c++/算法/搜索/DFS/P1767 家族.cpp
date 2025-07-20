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
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;
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
bool mp[101][201] = {};
int cnt = 0;
void dfs(int x, int y)
{
    mp[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if (x1 < n && x1 >= 0 && y1 < 201 && y1 >= 0 && mp[x1][y1] == 1)
        {
            dfs(x1, y1);
        }
    }
}

void solve()
{
    cin >> n;
    string ss;
    getline(cin, ss);
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        for (int j = 0; j < s.length(); j++)
        {
            char ch = s[j];
            if (ch == '*')
                mp[i][j] = 0;
            else if (ch == ' ')
                mp[i][j] = 0;
            else if (ch >= 'a' && ch <= 'z')
                mp[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 201; j++)
        {
            if (mp[i][j] == 1)
            {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}

int main()
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