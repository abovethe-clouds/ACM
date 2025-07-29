#include<bits/stdc++.h>
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
int dp[1145]={};
void solve()
{
    int h1, h2, m1, m2, n;
    vector<pair<int, int> > v;
    scanf("%d:%d %d:%d %d", &h1, &m1, &h2, &m2, &n);
    int time = (h2 - h1) * 60 + (m2 - m1);
    for (int i = 0; i < n; i++)
    {
        int t, c, p;
        cin >> t >> c >> p;
        if (p == 0)
            p = time;
        int b=1;
        while (p)
        {
            if (p>= b)
            {
                v.emplace_back(t*b, c*b);
                p -= b;
                b*=2;
            }
            else
            {
                v.emplace_back(t*p, c*p);
                p = 0;
            }
        }
    }
    for (auto &[c,v] : v)
    {
        for (int i = time; i >= 0; --i)
        {
            if (i-c>=0)
                dp[i]=max(dp[i],dp[i-c]+v);
        }
    }
    cout << dp[time];
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
