#include<bits/stdc++.h>
using namespace std;
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
int query(int op,int l,int r)
{
    cout<<op<<" "<<l<<" "<<r<<endl;
    cout.flush();
    return read();
}
void solve()
{
    int n=read();
    int standard=n*(n+1)/2;
    int sum=query(2,1,n);
    int dif=sum-standard;
    int l=1,r=n;
    while (l<r)
    {
        int mid=(l+r)/2;
        int now=query(2,l,mid);
        int stand=query(1,l,mid);
        if (stand<now)
            r=mid;
        else
            l=mid+1;
    }
    cout<<"! "<<l<<" "<<l+dif-1<<endl;
}
// 1 3 7 5 4 3 3

signed main()
{
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
// Created by Administrator on 2026/1/21.
//