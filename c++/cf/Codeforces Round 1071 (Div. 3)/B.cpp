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
    int n=read();
    vector<int> a(n);
    for (int i=0;i<n;i++)
        a[i]=read();
    vector<int> dif(n-1);
    for (int i=0;i<n-1;i++)
        dif[i]=abs(a[i+1]-a[i]);
    int ans=0;
    for (int i=0;i<n-1;i++)
        ans+=dif[i];
    int minn=ans;
    for (int i=0;i<n-2;i++)
    {
        ans-=dif[i];
        ans-=dif[i+1];
        ans+=abs(a[i+2]-a[i]);
        minn=min(minn,ans);
        ans+=dif[i];
        ans+=dif[i+1];
        ans-=abs(a[i+2]-a[i]);
    }
    ans-=dif[0];
    minn=min(minn,ans);
    ans-=dif[n-2];
    ans+=dif[0];
    minn=min(minn,ans);
    cout<<minn<<endl;
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
}//
// Created by Administrator on 2026/1/20.
//