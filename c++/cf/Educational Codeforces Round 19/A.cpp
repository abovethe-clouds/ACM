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

void solve()
{
    int n = read(), k = read(), cnt = 0;
    int ans = n;
    map<int, int> mp;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                n /= i;
                mp[i]++;
                cnt++;
            }
        }
    }
    if (n > 1)
        mp[n]++, cnt++;
    if (cnt >= k)
    {
        int cnt = 0;
        for (auto i: mp)
        {
            for (int j=0;j<i.second;j++)
            {
                if (cnt == k - 1)
                {
                    cout << ans << endl;
                    return;
                }
                cout << i.first << " " ;
                cnt++;
                ans/=i.first;
            }
        }
    } else
        cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
