#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 600;
struct edge
{
    int l, e1, e2;
    bool operator<(const edge &a) const
    {
        return l > a.l;
    }
};
priority_queue<edge> q;
vector<int> mp[maxn];
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
int A, B;
int fa[maxn], sum = 0, cnt;
void built()
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
void merge(int x, int y)
{
    fa[find(x)] = fa[find(y)];
    return;
}
void Kur()
{
    while (!q.empty() && cnt <= B - 1)
    {
        edge n = q.top();
        q.pop();
        int e1 = n.e1, e2 = n.e2, l = n.l;
        if (find(e1) != find(e2))
        {
            merge(e1, e2);
            cnt++;
            sum += l;
        }
    }
}
void solve()
{
    built();
    cin >> A >> B;
    for (int i = 1; i <= B; i++)
    {
        for (int j = 1; j <= B; j++)
        {
            int u;
            cin >> u;
            if (i == j)
                continue;
            if (u > A)
                u = A;
            if (u == 0)
                u = A;
            edge n;
            n.e1 = i, n.e2 = j, n.l = u;
            q.push(n);
        }
    }
    Kur();
    cout << sum + A;
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