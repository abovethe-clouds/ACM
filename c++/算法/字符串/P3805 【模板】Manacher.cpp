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
    string s;
    cin>>s;
    string t="#";
    for(auto c:s)
    {
        t.push_back(c);
        t.push_back('#');
    }
    int maxx=0;
    int r[t.size()]={0};
    int center=0,right=0;
    for (int i=0;i<t.size();i++)
    {
        if (i<right)
            r[i]=min(r[2*center-i],right-i);
        else
            r[i]=1;
        while(i-r[i]>=0&&i+r[i]<t.size()&&t[i-r[i]]==t[i+r[i]])
            r[i]++;
        if (i+r[i]>right)
        {
            right=i+r[i];
            center=i;
        }
        maxx=max(maxx,r[i]-1);

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
    //cin >> t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2026/1/14.
//