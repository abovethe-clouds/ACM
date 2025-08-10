#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int long long
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
struct pair_hash {
    size_t operator()(const pii &p) const noexcept {
        // 结合两个 int 的 hash，防止冲突
        return hash<long long>()(((long long)p.first << 32) ^ (long long)p.second);
    }
};
void solve()
{
    const int N = read();
    unordered_map<pii, int, pair_hash> cnt, ti;
    vector<pii> mp(N);
    for (int i = 0; i < N; ++i)
    {
        mp[i].first = read();
        mp[i].second = read();
    }
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < i; ++j)
        {
            cnt[{mp[i].first + mp[j].first, mp[i].second + mp[j].second}]++;
            int xx = mp[i].fir - mp[j].fir;
            int yy = mp[i].sec - mp[j].sec;
            if ((xx > 0 && yy > 0) || (xx < 0 && yy < 0) || xx == 0 || yy == 0)
            {
                xx = abs(xx);
                yy = abs(yy);
                const int gcd = __gcd(xx, yy);
                xx /= gcd;
                yy /= gcd;
            } else
            {
                xx = abs(xx);
                yy = -abs(yy);
                const int gcd = __gcd(xx, yy);
                xx /= gcd;
                yy /= gcd;
            }
            ti[make_pair(xx, yy)]++;
        }
    ll ans = 0, ans1 = 0; //平行四边形个数
    for (auto it = cnt.begin(); it != cnt.end(); ++it)
    {
        ans += it->second * 1ll * (it->second - 1) / 2;
    }

    for (auto it = ti.begin(); it != ti.end(); ++it)
        ans1 += it->second * 1ll * (it->second - 1) / 2;
    cout << ans1 - ans << endl;
}

signed main()
{
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
