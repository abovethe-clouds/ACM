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
    int n,m,cnt_0=0;
    cin >> n >> m;
    vector<int> v(n+2),num_1(n+2,0);
    vector<pii> op(m);
    for (int i = 0; i < m; i++)
    {
        cin >> op[i].fir >> op[i].sec;
        v[op[i].fir]++;
        v[op[i].sec+1]--;
    }
    for (int i = 1; i <= n; i++)
    {
        v[i] += v[i-1];
        if (v[i]==1)
            num_1[i]++;
    }
    for (int i = 1; i <= n; i++)
    {
        num_1[i] += num_1[i-1];
        if (v[i]==0)
            cnt_0++;
    }
    for (auto &[l,r] : op)
    {
        cout<<cnt_0+num_1[r]-num_1[l-1]<<endl;
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
    while (t--)
        solve();
    return 0;
}

//
// Created by Administrator on 2026/5/2.
//
