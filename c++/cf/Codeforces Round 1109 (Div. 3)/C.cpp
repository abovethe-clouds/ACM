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
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if (is_sorted(a.begin(),a.end()))
    {
        cout<<"YES"<<endl;
        return;
    }
    if (__gcd(x,y)==1)
    {
        cout<<"YES"<<endl;
        return;
    }
    int gcd=__gcd(x,y);
    vector<vector<int>> b(gcd);
    for(int i=0;i<n;i++)
    {
        b[i%gcd].push_back(a[i]);
    }
    for (int i = 0; i < gcd; i++)
    {
        sort(b[i].begin(), b[i].end());
    }
    vector<int> ans;
    for (int i=0;i<=n/gcd+1;i++)
    {
        for (int j=0;j<gcd;j++)
        {
            if (i<b[j].size())
            {
                ans.push_back(b[j][i]);
            }
            else
            {
                break;
            }
        }
    }
    if (is_sorted(ans.begin(),ans.end()))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
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
// Created by Administrator on 2026/7/14.
//