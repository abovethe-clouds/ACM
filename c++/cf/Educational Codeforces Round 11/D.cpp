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

pii in(pii a, pii b)
{
    pii n;
    n.first = a.first + b.first;
    n.second = a.second + b.second;
    return n;
}

void solve()
{
    const int N = read();
    map<pii, int> cnt;
    vector<pii> mp(N);
    for (int i = 0; i < N; ++i)
    {
        mp[i].first = read();
        mp[i].second = read();
    }
    for (int i = 1; i < N; ++i)
        for (int j = 0; j < i; ++j)
        {
            cnt[in(mp[i], mp[j])]++;
        }
    ll ans = 0;
    for (auto i: cnt)
        ans += i.second * (i.second - 1) / 2;
    cout << ans << endl;
}

void solve2()
{
    const int N = read();
    map<pii, int> cnt;
    vector<pii> mp(N);
    for (int i = 0; i < N; i++)
    {
        mp[i].first = read();
        mp[i].second = read();
    }
    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
        {
            int xx = mp[i].fir - mp[j].fir;
            int yy = mp[i].sec - mp[j].sec;
            if ((xx > 0 && yy > 0) || (xx < 0 && yy < 0) || xx == 0 || yy == 0)
            {
                xx = abs(xx);
                yy = abs(yy);
            } else
            {
                xx = abs(xx);
                yy = -abs(yy);
            }
            cnt[{xx, yy}]++;
        }
    ll ans = 0;
    for (auto i: cnt)
        ans += i.second * (i.second - 1) / 2;
    cout << ans / 2 << endl;
}

void solve3()
{
    int n, x[2003], y[2003];
    ll ans;
    map<pii, ll> mp;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int xx = x[i] - x[j], yy = y[i] - y[j];
            if ((xx > 0 && yy > 0) || (xx < 0 && yy < 0) || xx == 0 || yy == 0)xx = abs(xx), yy = abs(yy);
            else xx = abs(xx), yy = -abs(yy);
            mp[{xx, yy}]++;
        }
    for (auto p: mp)ans += p.second * (p.second - 1) / 2;
    cout << ans / 2;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve3();
    return 0;
} //
// Created by Administrator on 25-8-7.
//
