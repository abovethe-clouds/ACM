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
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    for (int i=0; i<n; i++)
    {
        int l=0,r=0;
        for (int j=i+1; j<n; j++)
        {
            if (v[j]>v[i])
                r++;
            else
                l++;
        }
        v[i]=max(l,r);
    }
    for (auto i : v)
        cout<<i<<" ";
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
// Created by Administrator on 2026/4/4.
//