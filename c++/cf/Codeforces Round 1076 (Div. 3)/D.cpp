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
    vector<int> a(n+1),sum(n+1,0);
    set<int> s;
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        s.insert(a[i]);
    }
    for (int i=1;i<=n;i++)
        sum[i]=sum[i-1]+read();
    sort(a.begin(),a.end());
    int maxx=-1;
    for (auto i:s)
    {
        int ans;
        int num=a.end()-lower_bound(a.begin(),a.end(),i);
        auto where=lower_bound(sum.begin(),sum.end(),num);
        if (where==sum.end())
            ans=i*n;
        else if (*where==num)
            ans=i*(where-sum.begin());
        else
            ans=i*(where-sum.begin()-1);
        maxx=max(maxx,ans);
    }
    cout<<maxx<<endl;
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