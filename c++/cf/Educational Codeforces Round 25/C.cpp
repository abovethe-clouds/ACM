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

pii judge(int pre, int next)
{
    int ans = 0;
    while (pre*2<next)
    {
        ans++;
        pre = pre*2;
    }
    return {ans,pre};
}

void solve()
{
    int n = read(), k = read();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = read();
    sort(a.begin(), a.end());
    int cnt = 0;
    cnt += judge(k, a[0]).first;
    int maxx = judge(k, a[0]).second;
    for (int i = 1; i < n; i++)
    {
        maxx = max(maxx, a[i - 1]);
        pii ne= judge(maxx, a[i]);
        cnt += ne.first;
        maxx = max(maxx, ne.second);
    }
    cout << cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 2025/8/26.
//
