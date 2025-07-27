#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 205;
int l[maxn][maxn], n, m;
pii t[maxn];
void built()
{
    for (int i = 0; i < maxn; i++)
    {
        for (int j = 0; j < maxn; j++)
        {
            if (i == j)
                l[i][j] = 0;
            else
                l[i][j] = inf;
        }
    }
}
void floyd(int x)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            l[i][j] = min(l[i][j], l[i][x] + l[x][j]);
        }
    }
}
void solve()
{
    built();
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i].first;
        t[i].second = i;
    }
    sort(t, t + n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        l[a][b] = c;
        l[b][a] = c;
    }
    int w, now = 0;
    cin >> w;
    while (w--)
    {
        int time, a, b;
        cin >> a >> b >> time;
        while (time >= t[now].first && now < n)
        {
            floyd(t[now].second);
            now++;
        }
        if (t[a].first > time || t[b].first > time || l[a][b] == inf)
            cout << -1 << endl;
        else
            cout << l[a][b] << endl;
    }
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
    // cin >> t;
    while (t--)
        solve();

    return 0;
}