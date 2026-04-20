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
    int n,m;
    cin>>n>>m;
    vector<int> a(m+1),b[m+2];
    for(int i=1;i<=m;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        b[x].push_back(i);
    }
    vector<int> ans;
    for(int i=0;i<=m;i++)
    {
        for (auto j:b[m-i])
        {
            for (int k=0;k<=i;k++)
                ans.push_back(j);
        }
        if (ans.size()>1000)
            break;
    }
    if (ans.size()>1000)
    {
        cout<<-1<<endl;
        return;
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
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
// Created by Administrator on 2026/4/14.
//