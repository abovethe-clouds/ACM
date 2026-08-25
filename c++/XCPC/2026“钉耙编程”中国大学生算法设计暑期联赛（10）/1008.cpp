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
const int mod = 1e9 + 7, inf = LONG_LONG_MAX, P = 131;
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }
    vector<int> pre(n + 1, 0), maxl(n + 1, -inf), maxr(n + 2, -inf);
    maxl[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        maxl[i] = max(maxl[i - 1], pre[i]);
    }
    maxr[n] = pre[n];
    for (int i = n - 1; i >= 1; i--)
    {
        maxr[i] = max(maxr[i + 1], pre[i]);
    }
    int ans = -inf;
    for (int i = 1; i <= n; i++)
    {
        int _ans = maxl[i] + maxr[i + 1] - pre[i];
        ans = max(ans, _ans);
        ans = max(ans, pre[i]);
    }
    cout << ans << endl;
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
} //
// Created by Administrator on 2026/8/20.
//
