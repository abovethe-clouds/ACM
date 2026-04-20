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

vector<pii> find_prime_pow(int x)
{
    vector<pii> res;
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0)
            {
                cnt++;
                x /= i;
            }
            res.emplace_back(i, cnt);
        }
    }
    if (x > 1)
        res.emplace_back(x, 1);
    return res;
}

void solve()
{
    int n;
    cin >> n;
    int ans=1;
    vector<pii> v=find_prime_pow(n);
    for(auto [p,cnt]:v)
    {
        ans*=pow(p,ceil(cnt*1.0/n));
    }
    cout<<ans<<endl;
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
    cin>>t;
    while (t--)
        solve();
    return 0;
}

//
// Created by Administrator on 2026/3/14.
//
