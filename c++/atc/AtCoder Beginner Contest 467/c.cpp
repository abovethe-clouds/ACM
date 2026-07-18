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

void solve()
{
    int n,m;
    cin >> n>> m;
    vector<int> a(n),b(n-1);
    for (auto &x:a) cin >> x;
    for (auto &x:b) cin >> x;
    int ans1=0,ans=0;
    vector<int> a1=a;
    if (a1[0]==0)
        a1[0]=1,ans1++;
    for (int i=0;i<n-1;i++)
    {
        if ((a1[i]+a1[i+1])%m!=b[i])
        {
            ans1++;
            a1[i+1]++;
            a1[i+1]%=m;
        }
    }
    if (a[0]==1)
        a[0]=0,ans++;
    for (int i=0;i<n-1;i++)
    {
        if ((a[i]+a[i+1])%m!=b[i])
        {
            ans++;
            a[i+1]++;
            a[i+1]%=m;
        }
    }
    cout << min(ans,ans1) << endl;

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
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2026/7/19.
//