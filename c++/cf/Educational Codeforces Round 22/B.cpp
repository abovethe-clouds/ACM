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

ll read()
{
    ll x = 0, w = 1;
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
    ll x=read(),y=read(),l=read(),r=read();
    vector<__int128_t> x_pow,y_pow;
    for (__int128_t ans = 1; ans <=r; )
    {
        x_pow.push_back(ans);
        ans*=x;
    }
    for (__int128_t ans = 1; ans <= r; )
    {
        y_pow.push_back(ans);
        ans*=y;
    }
    vector<__int128_t> unLack;
    for (auto o : x_pow)
    {
        auto it=lower_bound(y_pow.begin(), y_pow.end(), l-o);
        while (it != y_pow.end() && *it+o <= r)
        {
            unLack.push_back(o+(*it++));
        }
    }
    unLack.erase(unique(unLack.begin(), unLack.end()), unLack.end());
    unLack.push_back(l-1);
    sort(unLack.begin(), unLack.end());
    if (unLack.empty())
    {
        cout<<r-l+1;
        return;
    }
    unLack.push_back(r+1);
    ll sum=0;
    for (int i = 1; i < unLack.size(); i++)
    {
        sum=max(unLack[i]-unLack[i-1]-1,__int128_t(sum));
    }
    cout<<sum<<endl;
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
}//
// Created by Administrator on 2025/8/21.
//