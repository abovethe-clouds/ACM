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
        cout<<"1"<<endl;
        return;
    }
    if (n==2)
    {
        cout<<"1 2"<<endl;
        return;
    }
    vector<bool> v(2*n+1);
    int t=3;
    vector<int> ans;
    ans.push_back(1);
    v[1]=true;
    ans.push_back(2);
    v[2]=true;
    v[3]=true;
    while (ans.size()<n)
    {
        if (!v[t])
        {
            if (ans.back()+t<=2*n)
                v[ans.back()+t]=true;
            ans.push_back(t);
            v[t]=true;
        }
        t++;
    }
    for (auto i:ans)
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
// Created by Administrator on 2026/5/27.
//