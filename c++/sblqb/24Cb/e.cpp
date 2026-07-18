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
    int a,b;
    string s,add;
    cin>>a>>b>>s>>add;
    sort(add.begin(), add.end());
    reverse(add.begin(), add.end());
    reverse(s.begin(), s.end());
    string ans;
    while ((!add.empty())&&(!s.empty()))
    {
        if (add.back()>=s.back())
        {
            ans.push_back(s.back());
            s.pop_back();
        }
        else
        {
            ans.push_back(add.back());
            add.pop_back();
        }
    }
    while (!s.empty())
    {
        ans.push_back(s.back());
        s.pop_back();
    }
    while (!add.empty())
    {
        ans.push_back(add.back());
        add.pop_back();
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
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2026/5/1.
//