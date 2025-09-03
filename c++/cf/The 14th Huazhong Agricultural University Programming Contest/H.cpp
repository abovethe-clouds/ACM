#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
#define int ll
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
    const int n=read();
    vector<pii> point(n);
    for(int i=0; i<n; i++)
    {
        point[i].first = read();
    }
    for(int i=0; i<n; i++)
    {
        point[i].second = read();
    }
    point.erase(unique(point.begin(),point.end()),point.end());
    map<int,int> a,b;
    for (auto i:point)
    {
        a[i.first]++;
        b[i.second]++;
    }
    ll ans=0;
    for(auto &[l,i]:a)
    {
        if (i>1)
        {
            ans+=i*(i-1)/2;
        }
    }
    for(auto &[l,i]:b)
    {
        if (i>1)
        {
            ans+=i*(i-1)/2;
        }
    }
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
    int t = read();
    //cin >> t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2025/9/1.
//