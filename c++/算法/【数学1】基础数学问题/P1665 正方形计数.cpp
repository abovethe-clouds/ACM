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
map<pii, bool> mp;
void solve()
{
    int n;
    cin >> n;
    pii a[n];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        mp[a[i]] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            pii o, oo;
            o.first = a[j].second - a[i].second + a[i].first;
            o.second = a[i].first - a[j].first + a[i].second;
            oo.first = a[j].second + a[j].first - a[i].second;
            oo.second = a[i].first - a[j].first + a[j].second;
            if (mp[o] && mp[oo])
            {
                cnt++;
            }
        }
    }
    cout << cnt / 4;
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