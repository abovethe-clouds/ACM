#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=1e5;
struct pt
{
    int x, y;
};
void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]++;
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, x2--;
    vector<vector<int>> dis(101 ,vector<int>(maxn, -1));
    queue<pii> q;
    q.emplace(x1,y1);
    dis[x1][y1]=0;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if (x == x2 && y == y2)
        {
            cout << dis[x][y] << endl;
            return;
        }
        int next = dis[x][y] + 1;
        if (y > 1 && dis[x][y-1] == -1)
        {
            dis[x][y-1] = next;
            q.emplace(x, y - 1);
        }
        if (y < a[x] && dis[x][ y + 1] == -1)
        {
            dis[x][ y + 1] = next;
            q.emplace(x, y + 1);
        }
        if (x > 0)
        {
            int minn = min(y, a[x - 1]);
            if (dis[x - 1] [minn] == -1)
            {
                dis[x - 1][minn] = next;
                q.push({x - 1, minn});
            }
        }
        if (x + 1 < n)
        {
            int minn = min(y, a[x + 1]);
            if (dis[x + 1][minn] == -1)
            {
                dis[x + 1][ minn] = next;
                q.emplace(x + 1, minn);
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE

#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
