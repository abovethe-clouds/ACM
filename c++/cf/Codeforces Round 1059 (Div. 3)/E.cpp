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
    int n=read(),k=read();
    vector<int> a(n);
    vector<bool> used(n+1,false);
    for (int i=0;i<n;i++)
        a[i]=read(),used[a[i]]=true;
    vector<int> unused;
    for (int i=1;i<=n;i++)
    {
        if (!used[i])
            unused.emplace_back(i);
    }
    if (unused.empty())
    {
        for (int i=0;i<k;i++)
            cout<<a[i%3]<<" ";
    }
    else
    {
        if (unused.size()>=3)
        {
            for (int i=0;i<k;i++)
                cout<<unused[i%3]<<" ";
        }
        else
        {
            int i=0;

            while (unused.size()<2)
            {
                if (find(unused.begin(),unused.end(),a[i])==unused.end()&&a[i]!=a.back())
                    unused.emplace_back(a[i]);
                i++;
            }
            unused.emplace_back(a.back());
            for (int i=0;i<k;i++)
                cout<<unused[i%3]<<" ";

        }
    }
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
}//
// Created by Administrator on 2026/1/21.
//