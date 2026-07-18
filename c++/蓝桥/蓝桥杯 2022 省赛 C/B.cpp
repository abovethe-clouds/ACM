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

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int week=n*5+m*2;
    int week_cnt=k/week;
    int day=k%week;
    int sum=week_cnt*7;
    if (day<=n*5)
    {
        sum+=day/n;
        day=day%n;
        if (day)
            sum++;
    }
    else
    {
        sum+=5;
        day-=n*5;
        sum+=day/m;
        day=day%m;
        if (day)
            sum++;
    }
    cout<<sum<<endl;
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
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2026/4/7.
//