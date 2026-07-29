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
    int n;
    cin>>n;
    int ans=0;
    vector<int> l(n),r(n),u(n),v(n);
    for (int i = 0; i < n; i++)
        cin>>l[i]>>r[i]>>u[i]>>v[i];
    for(int i = n; i >= 0; i--)
    {
        int cnt = 0;
        for(int j = 0; j < n; j++)
        {
            if(cnt == i)
                break;
            int w = cnt + 1;
            if((w < l[j] || w > r[j]) &&
               (i - w + 1 < u[j] || i - w + 1 > v[j]))
            {
                cnt++;
            }
        }
        if(cnt == i)
        {
            ans = i;
            break;
        }
    }
    cout<<ans<<endl;

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
    cin >> t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2026/7/26.
//