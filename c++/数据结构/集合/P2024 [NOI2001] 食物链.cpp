#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 5e6 + 5;
int fa[maxn];
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
void merge(int x, int y)
{

    int fx = find(x), fy = find(y);

    fa[fx] = fy;
}
void solve()
{
    build();
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> c >> a >> b;
        if (a > n || b > n)
        {
            cnt++;
        }
        else
        {
            if (c == 1)
            {
                if (find(b) == find(a + n) || find(b) == find(a + n + n))
                    cnt++;
                else
                {
                    merge(a, b);
                    merge(a + n, b + n);
                    merge(a + n + n, b + n + n);
                }
            }
            else
            {
                if (a == b || find(a) == find(b) || find(a + n + n) == find(b)) // b是a的猎物
                {
                    cnt++;
                }
                else
                {
                    merge(b + n + n, a);     // b天敌=a
                    merge(b + n, a + n + n); // b食物==a天敌
                    merge(a + n, b);
                }
            }
        }
    }
    cout << cnt;
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