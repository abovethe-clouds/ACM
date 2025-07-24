#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 1e5 + 5;
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
struct edge
{
    int e1, e2, l;
};
vector<pii> G[maxn];
int in[maxn];
int N, M, C;
int S[maxn];
void solve()
{
    cin >> N >> M >> C;
    for (int i = 1; i <= N; i++)
    {
        cin >> S[i];
    }
    for (int i = 0; i < C; i++)
    {
        edge n;
        cin >> n.e1 >> n.e2 >> n.l;
        in[n.e2]++;
        G[n.e1].push_back(make_pair(n.e2, n.l));
    }
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (in[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int b = q.front();
        q.pop();
        for (auto i : G[b])
        {
            if (S[i.first] < S[b] + i.second)
                S[i.first] = S[b] + i.second;
            in[i.first]--;
            if (in[i.first] == 0)
                q.push(i.first);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cout << S[i] << endl;
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