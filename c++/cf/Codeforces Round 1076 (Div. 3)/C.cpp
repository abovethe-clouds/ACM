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
    int n=read(),m=read();
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++)
        a[i]=read();
    for (int i=1;i<=n;i++)
        b[i]=read();
    deque<pii> q;//value,index
    int maxx=0;
    for (int i=1;i<=n;i++)
    {
        if (maxx<a[i]||maxx<b[i])
        {
            maxx=max(a[i],b[i]);
            while (!q.empty()&&q.back().fir<=maxx)
                q.pop_back();
            q.emplace_back(maxx,i);
            maxx=0;
        }
    }
    vector<int> sum(n+1,0);
    for (int i=1;i<=n;i++)
    {
        if (i>q.front().sec)
            q.pop_front();
        if (i<=q.front().sec)
        {
            sum[i]=sum[i-1]+q.front().first;
        }
    }
    while (m--)
    {
        int l=read(),r=read();
        cout<<sum[r]-sum[l-1]<<" ";
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
// Created by Administrator on 2026/1/25.
//