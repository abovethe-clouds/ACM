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
    int n=read(),m=read(),h=read();
    vector<int> a(n);
    for (int i=0;i<n;i++) a[i]=read();
    vector<int> standard=a;
    vector<int> op;
    for (int i=0;i<m;i++)
    {
        int where=read()-1,what=read();
        a[where]+=what;
        op.emplace_back(where);
        if (a[where]>h)
        {
            for (auto it:op)
            {
                a[it]=standard[it];
            }
            op.clear();
        }
    }
    for (int i=0;i<n;i++) cout<<a[i]<<" ";
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
// Created by Administrator on 2026/1/18.
//
