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
    const int n=read(),k=read();
    vector<int> a(n);
    for(int i=0;i<n;i++)
        a[i]=read();
    int w=a[k-1];
    sort(a.begin(),a.end());
    int begin=lower_bound(a.begin(),a.end(),w)-a.begin();
    int high=1;
    for(int i=begin;i<n-1;i++)
    {
        int time=a[i+1]-a[i];
        if(a[i]<high+time-1)
        {
            cout<<"NO"<<endl;
            return;
        }
        high+=time;
    }
    cout<<"YES"<<endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = read();
    //cin >> t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2025/9/2.
//