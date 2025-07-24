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
vector<int> mp[501];
int in[501];
bool c[501];
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int w, h;
        cin >> w >> h;
        c[w] = 1;
        while (h--)
        {
            int t;
            cin >> t;
            in[t]++;
            mp[w].push_back(t);
        }
    }
    queue<int> q;
    for (int i = 0; i < 501; i++)
    {
        if (in[i] == 0 && c[i])
            q.push(i);
    }
    while (!q.empty())
    {
        int b = q.front();
        q.pop();
        n--;
        for (auto i : mp[b])
        {
            in[i]--;
            if (in[i] == 0 && c[i])
                q.push(i);
        }
    }
    if (n == 0)
        cout << "YES";
    else
        cout << n;
    return;
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