#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;

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
ll c[2005][2005], sum[2005][2005], flag[2005][2005], k, t;

void solve()
{
    c[0][0] = 1;
    c[1][1] = 1;
    c[1][0] = 1;
    for (int i = 2; i < 2001; i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            if (c[i][j] == 0)
                sum[i][j]++;
        }
        sum[i][i + 1] = sum[i][i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin >> t >> mod;
    solve();
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[l][min(r, l)] << endl;
    }

    return 0;
}