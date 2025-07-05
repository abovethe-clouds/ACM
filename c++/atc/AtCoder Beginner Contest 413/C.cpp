#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
#define int ll
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
deque<pii> q;
void add(int c, int x)
{
    q.push_back({c, x});
}
int find(int x)
{
    int ans = x;
    int sum = 0;
    while (ans)
    {
        pii f = q.front();
        q.pop_front();
        if (f.first <= ans)
        {
            ans -= f.first;
            sum += f.first * f.second;
        }
        else
        {
            sum += ans * f.second;
            f.first -= ans;
            ans = 0;
            q.push_front(f);
        }
    }
    return sum;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int c, x;
            cin >> c >> x;
            add(c, x);
        }
        else
        {
            int k;
            cin >> k;
            cout << find(k) << endl;
        }
    }
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
    // cin >> t;
    while (t--)
        solve();

    return 0;
}