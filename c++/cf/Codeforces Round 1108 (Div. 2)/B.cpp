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
    int n;
    cin>>n;
    if (n==1)
    {
        cout<<1<<endl;
        return;
    }
    if (n==2)
    {
        cout<<-1<<endl;
        return;
    }
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    int sum=3;
    for (int i=2;i<n;i++)
    {
        a.push_back(sum);
        sum+=a[i];
    }
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
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
// Created by Administrator on 2026/7/12.
//