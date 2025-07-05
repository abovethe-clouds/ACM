#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 4e5 + 5;

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
int fa[maxn], n, m, br[maxn] = {};
vector<int> mp[maxn];
void build()
{
    for (int i = 0; i < maxn; i++)
    {
        fa[i] = i;
    }
    return;
}
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
bool merge(int x, int y)
{

    int fx = find(x), fy = find(y);
    if (fx == fy)
        return 0;
    fa[fx] = fy;
    return 1;
}
set<int> st;
int judge()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (!st.count(i) && fa[i] == i)
            cnt++;
    }
    return cnt;
}
void solve()
{
    cin >> n >> m;

    build();
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> br[i];
        st.insert(br[i]);
    }
    stack<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (st.count(i))
            continue;
        for (auto j : mp[i])
        {
            if (st.count(j))
                continue;
            merge(i, j);
        }
    }
    int cnt = judge();
    ans.push(cnt);
    for (int i = k - 1; i >= 0; i--)
    {
        st.erase(br[i]);
        cnt++;
        for (auto j : mp[br[i]])
        {
            if (st.count(j))
                continue;
            if (merge(br[i], j))
                cnt--;
        }
        ans.push(cnt);
    }
    while (!ans.empty())
    {
        cout << ans.top() << endl;
        ans.pop();
    }
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