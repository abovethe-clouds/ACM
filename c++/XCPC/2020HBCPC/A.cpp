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

void solve()
{
    int h,m;
    string s;
    char c;
    cin>>h>>c>>m>>s;
    if (s=="7-1")
    {
        m+=5;
        if (m>=60)
        {
            m-=60;
            h++;
        }
        printf("%02d:%02d\n",h,m);
        return;
    }
    cout<<"05:05"<<endl;

}

signed main()
{
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
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
// Created by Administrator on 2026/5/7.
//