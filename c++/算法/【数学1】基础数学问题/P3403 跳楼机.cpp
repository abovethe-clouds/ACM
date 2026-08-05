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
const int mod = 1e9 + 7, inf = LONG_LONG_MAX, P = 131, maxn=1e5+5;
vector<bool> vis(maxn,false);
vector<int> val(maxn,inf);
vector<pii> mp[maxn];
void dijkstra(int start)
{
    val[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, start);
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [v, w] : mp[u])
        {
            if (!vis[v] && val[u] + w < val[v])
            {
                val[v] = val[u] + w;
                pq.emplace(val[v], v);
            }
        }
    }
}
void solve()
{
    int h,a[3];
    cin>>h>>a[0]>>a[1]>>a[2];
    h--;
    sort(a,a+3);
    for (int i=0;i<a[0];i++)
    {
        mp[i].emplace_back((i+a[1])%a[0],a[1]);
        mp[i].emplace_back((i+a[2])%a[0],a[2]);
    }
    dijkstra(0);
    int ans=0;
    for (int i=0;i<a[0];i++)
    {
        if (val[i]<=h)
        {
            ans+=(h-val[i])/a[0]+1;
        }
    }
    cout<<ans<<endl;
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
    while (t--)
        solve();
    return 0;
}
