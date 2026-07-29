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
double sml=1e-6;
void solve(int n,int m)
{
    vector<int> a(n),b(n);
    m=n-m;
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    double l=0,r=1.5,ans=0;
    auto  check=[=](double check_val)
    {
        vector<double> dp(n);
        for (int i=0;i<n;i++)
        {
            dp[i]=a[i]-check_val*b[i];
        }
        sort(dp.begin(),dp.end(),greater<double>());
        double sum=0;
        for (int i=0;i<m;i++)
        {
            sum+=dp[i];
        }
        return sum>0;
    };
    while (r-l>sml)
    {
        double mid=(l+r)/2;
        if (check(mid))
            l=mid,ans=mid;
        else
            r=mid;
    }
    cout<< static_cast<ll>(ans * 100+0.5)<<endl;

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
    //cin >> t;
    int n,m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            return 0;
        solve(n,m);
    }
    return 0;
}//
// Created by Administrator on 2026/7/26.
//