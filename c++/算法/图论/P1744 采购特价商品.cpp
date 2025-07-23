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
#define pdi pair<double, int>
const int maxn = 2e5;
int n, m, s;
map<int, pii> where;
vector<pdi> mp[maxn];
double l[maxn];
bool vis[maxn];
double ou(pii x, pii y)
{
    double ans = (y.first - x.first) * (y.first - x.first) + (y.second - x.second) * (y.second - x.second);
    ans = sqrt(ans);
    return ans;
}
void dij()
{
    fill(l, l + maxn, 1e9);
    l[s] = 0;
    priority_queue<pdi, vector<pdi>, greater<pdi>> q;
    q.push(make_pair(l[s], s));
    while (!q.empty())
    {
        pdi x = q.top();
        q.pop();
        if (vis[x.second])
            continue;
        vis[x.second] = 1;
        for (auto a : mp[x.second])
        {
            if (l[x.second] + a.first < l[a.second])
            {
                q.push(make_pair(x.first + a.first, a.second));
                l[a.second] = l[x.second] + a.first;
            }
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> where[i].first >> where[i].second;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        double c = ou(where[a], where[b]);
        mp[a].push_back(make_pair(c, b));
        mp[b].push_back(make_pair(c, a));
    }
    cin >> s;
    dij();
    int e;
    cin >> e;
    printf("%.2f", l[e]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}