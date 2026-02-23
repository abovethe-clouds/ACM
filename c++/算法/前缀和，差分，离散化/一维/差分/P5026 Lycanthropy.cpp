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
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=1e6+5,pian=30000+5;
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
vector<int> sub(pian+maxn+pian, 0);
void _set(int start,int end,int d,int l,int r)
{
    sub[l+pian]+=start;
    sub[l+1+pian]+=d-start;
    sub[r+1+pian]-=end+d;
    sub[r+2+pian]+=end;
}
void solve()
{
    int m= read(), n = read();
    for (int i = 1; i <= m; ++i)
    {
        int v= read(), x = read();
        _set(1,v,1,x-3*v+1,x-2*v);
        _set(v-1,-v,-1,x-2*v+1,x);
        _set(-v+1,v,1,x+1,x+2*v);
        _set(v-1,1,-1,x+2*v+1,x+3*v-1);
    }
    for (int i = 1; i <= n+pian; ++i)
    {
        sub[i] += sub[i - 1];
    }
    for (int i = 1; i <= n+pian; ++i)
    {
        sub[i] += sub[i - 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << sub[i+pian] << " ";
    }
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