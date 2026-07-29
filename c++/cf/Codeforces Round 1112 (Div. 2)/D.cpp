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
    cin >> n;
    vector<int> a(n + 1);
    vector<bool> pre(n + 1), suf(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != n) continue;
        cout << 0 << endl;
        return;
    }
    pre[0] = 1, suf[n] = 1;
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] && a[i] >= a[i - 1];
    for (int i = n - 1; i >= 1; i--)
        suf[i] = suf[i + 1] && a[i] >= a[i + 1];
    long long ans = 0;
    
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
// Created by Administrator on 2026/7/27.
//
