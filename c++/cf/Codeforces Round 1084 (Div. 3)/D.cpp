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
int read()
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

void solve()
{
    int n = read(), l = read(), r = read();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = read();
    vector<int> zhong(r - l);
    for (int i = l + 1; i <= r; i++)
        zhong[i - (l + 1)] = a[i];
    pii min_zhong = {inf, 0};
    for (int i = 0; i < zhong.size(); i++)
        min_zhong = min(min_zhong, {zhong[i], i});
    vector<int> ans;
    for (int i = min_zhong.second; i < zhong.size(); i++)
        ans.push_back(zhong[i]);
    for (int i = 0; i < min_zhong.second; i++)
        ans.push_back(zhong[i]);
    vector<int> pre;
    for (int i=1; i<=l; i++)
        pre.push_back(a[i]);
    for (int i=r+1; i<=n; i++)
        pre.push_back(a[i]);
    int i;
    for (i=0; i<pre.size(); i++)
    {
        if (pre[i]<ans[0])
            cout<<pre[i]<<" ";
        else
            break;
    }

    for (auto j: ans)
        cout<<j<<" ";
    for (;i<pre.size(); i++)
        cout<<pre[i]<<" ";
    cout<<endl;
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
    t = read();
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 2026/2/28.
//
