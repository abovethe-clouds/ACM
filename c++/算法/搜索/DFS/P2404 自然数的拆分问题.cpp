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
int n, a[10] = {1};
void dfs(int c, int sum)
{
    if (sum == n)
    {
        for (int i = 1; i <= c - 2; i++)
            cout << a[i] << "+";
        cout << a[c - 1] << endl;
        return;
    }
    int x = n - sum;
    for (int i = a[c - 1]; i <= x; i++)
    {
        if (i == n)
            break;
        sum += i;
        a[c] = i;
        dfs(c + 1, sum);
        sum -= i;
    }
    return;
}
void solve()
{
    cin >> n;
    dfs(1, 0);
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