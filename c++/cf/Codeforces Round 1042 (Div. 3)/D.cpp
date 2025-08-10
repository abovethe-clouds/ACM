#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=2e5+7;

int read()
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
vector<int> mp[maxn];
bool vis[maxn];

int dfs(int n, int p, int h)
{
    vis[n] = true;
    bool l = true;
    int ans = 0;
    for (auto nxt : mp[n])
    {
        if (nxt != p && !vis[nxt])
        {
            l = false;
            ans += dfs(nxt, n, h + 1);
        }
    }
    if (l && h >= 2)
        ans++;
    return ans;
}

void solve()
{
    int N = read();
    for (int i = 1; i <= N; i++) {
        mp[i].clear();
        vis[i] = false;
    }
    int cnt[N+1]={0};
    for (int i = 1; i < N; i++)
    {
        int a = read(), b = read();
        mp[a].push_back(b);
        mp[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
    }
    pii maxx = {-1, -1};
    for (int i = 1; i <= N; i++)
        if (cnt[i] > maxx.second)
            maxx = {i, cnt[i]};
    cout << dfs(maxx.first, -1, 0) << endl;
}
int main()
{

#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = read();
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
