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
    int n = read(), m = read();
    vector<int> sub(n + 3, 0);
    for (int i = 1; i <= m; ++i)
    {
        int l= read(), r = read(), s = read(), e= read();
        sub[l] += s;
        int d=(e-s)/(r-l);//公差
        sub[l+1]+=d-s;
        sub[r+1]-=e+d;
        sub[r+2]+=e;

    }
    for (int i = 1; i <= n; ++i)
    {
        sub[i] += sub[i - 1];
    }
    int xor_sum = 0,maxx=-1;
    for (int i = 1; i <= n; ++i)
    {
        sub[i] += sub[i - 1];
        xor_sum ^= sub[i];
        maxx=max(maxx,sub[i]);
    }
    cout << xor_sum << " " << maxx << endl;
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
    //t = read();
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2026/2/23.
//