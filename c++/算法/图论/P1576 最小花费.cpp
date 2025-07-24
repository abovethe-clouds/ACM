#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<double, int> pdi;
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
vector<pair<int, double>> mp[2001];
bool vis[2001];
double l[2001];
int n, m;
void dij(int start)
{
    fill(l, l + 2001, 0);
    priority_queue<pair<double, int>> q;
    // vis[start] = 1;
    l[start] = 1;
    q.push(make_pair(1, start));
    while (!q.empty())
    {
        pdi b = q.top();
        q.pop();
        if (vis[b.second])
            continue;
        vis[b.second] = 1;

        for (auto i : mp[b.second])
        {
            if (i.second * b.first > l[i.first])
            {
                l[i.first] = i.second * b.first;
                q.push(make_pair(l[i.first], i.first));
            }
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int b, e, t;
        cin >> b >> e >> t;
        mp[b].push_back(make_pair(e, 1 - 0.01 * t));
        mp[e].push_back(make_pair(b, 1 - 0.01 * t));
    }
    int b, e;
    cin >> b >> e;
    dij(b);
    printf("%.8f", 100 / l[e]);
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