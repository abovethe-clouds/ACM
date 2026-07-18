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
    string s;
    int n;
    cin>>n;
    cin>>s;
    vector<int> a(s.length()+1);
    for(int i=0;i<s.length();i++)
    {
        if (s[i]=='#')
        {
            a[i+1]=a[i]+1;
        }
        else
        {
            a[i+1]=0;
        }
    }
    int x=*max_element(a.begin(),a.end());
    cout<<(x+1)/2<<endl;
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