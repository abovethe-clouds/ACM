#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll bmul(ll a, ll b, ll m) {  // 快速乘
    ull c = (ull)a * (ull)b - (ull)((long double)a / m * b + 0.5L) * (ull)m;
    if (c < (ull)m) return c;
    return c + m;
}

ll qpow(ll x, ll p, ll mod) {  // 快速幂
    ll ans = 1;
    while (p) {
        if (p & 1) ans = bmul(ans, x, mod);
        x = bmul(x, x, mod);
        p >>= 1;
    }
    return ans;
}

bool Miller_Rabin(ll p) {  // 判断素数
    if (p < 2) return false;
    if (p == 2) return true;
    if (p == 3) return true;
    ll d = p - 1, r = 0;
    while (!(d & 1)) ++r, d >>= 1;  // 将d处理为奇数
    for (ll k = 0; k < 10; ++k) {
        ll a = rng() % (p - 2) + 2;
        ll x = qpow(a, d, p);
        if (x == 1 || x == p - 1) continue;
        for (int i = 0; i < r - 1; ++i) {
            x = bmul(x, x, p);
            if (x == p - 1) break;
        }
        if (x != p - 1) return false;
    }
    return true;
}

ll Pollard_Rho(ll x) {
    ll s = 0, t = 0;
    ll c = (ll)rng() % (x - 1) + 1;
    int step = 0, goal = 1;
    ll val = 1;
    for (goal = 1;; goal *= 2, s = t, val = 1) {  // 倍增优化
        for (step = 1; step <= goal; ++step) {
            t = (bmul(t, t, x) + c) % x;
            val = bmul(val, abs(t - s), x);
            if ((step % 127) == 0) {
                ll d = gcd(val, x);
                if (d > 1) return d;
            }
        }
        ll d = gcd(val, x);
        if (d > 1) return d;
    }
}

void fac(ll x, map<ll,int>& mp)
{
    if(x < 2) return;

    if(Miller_Rabin(x))
    {
        mp[x]++;
        return;
    }
    ll p = Pollard_Rho(x);
    fac(p, mp);
    fac(x / p, mp);
}
void solve()
{
    int n;
    cin>>n;
    map<int,int> mp;
    fac(n,mp);
    int maxx=0;
    for (auto [a,b]:mp)
    {
        maxx=max(maxx,b);

    }
    cout<<static_cast<ll>(log2(maxx))+1<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2026/7/28.
//