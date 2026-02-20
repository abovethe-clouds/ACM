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
int C2(int x)
{
    return x*(x+1)/2;
}
void solve()
{
    int n=read(),D=read();
    vector<int> v(n),dis(n,0);
    for (int i=0;i<n;i++)
        v[i]=read();

    for (int i=1;i<n;i++)
    {
        if (abs(v[i]-v[i-1])>=D)
            dis[i]=dis[i-1]+1;
        else
            dis[i]=0;
    int ans=0;
    for (int i=0;i<n-1;i++)
    {
        if (dis[i]!=0&&dis[i+1]==0)
        {
            ans+=C2(dis[i]);
        }
    }
    if (dis[n-1]!=0)
        ans+=C2(dis[n-1]);
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
    //t = read();
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2026/2/7.
//