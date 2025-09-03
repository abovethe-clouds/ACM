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
    const int n=read();
    int maxx=INT_MIN,minn=INT_MAX;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        a[i]=read();
        maxx = max(maxx,a[i]);
        minn = min(minn,a[i]);
    }
    if (n==1)
    {
        cout<<1<<endl;
        return;
    }
    if ((a[0]==minn&&a[n-1]==maxx)||(a[0]==maxx&&a[n-1]==minn))
    {
        cout<<2<<endl;
        return;
    }
    int where_max=lower_bound(a.begin(),a.end(),maxx)-a.begin(),where_min=lower_bound(a.begin(),a.end(),minn)-a.begin();
    int cnt=0;
    for (int i=1;i<min(where_max,where_min);i++)
    {
        if (a[i]>=a[0]&&a[i]<=maxx)
            continue;
        if (a[i]<=a[0]&&a[i]>=where_min)
            continue;
        cnt++;
    }
    for (int i=max(where_max,where_min)+1;i<n-1;i++)
    {
        if (a[i]>=a[n-1]&&a[i]<=maxx)
            continue;
        if (a[i]<=a[n-1]&&a[i]>=where_min)
            continue;
    }
    cout<<cnt+((a[0]==maxx||a[0]==minn||a[n-1]==maxx||a[n-1]==minn)?3:4)<<endl;

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
    //cin >> t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2025/9/2.
//