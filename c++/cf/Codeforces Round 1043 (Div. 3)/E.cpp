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

void solve()
{
    const int n = read(), m = read(), q = read();
    int a[n+1],suma[n+1],b[m+1],sumb[m+1];
    for (int i = 1; i <= n; i++)
    {
        a[i]=read();
    }
    sort(a+1,a+n+1,[](int a,int b){return a>b;});
    for (int i = 1; i <= m; i++)
    {
        b[i]=read();
    }
    sort(b+1,b+m+1,[](int a,int b){return a>b;});
    for (int i = 1; i <= n; i++)
        suma[i]=suma[i-1]+a[i];
    for (int i = 1; i <= m; i++)
        sumb[i]=sumb[i-1]+suma[i]+b[i];

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
    int t = read();
    //cin >> t;
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 2025/8/22.
//
