#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int long long
typedef unsigned long long ull;
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
    int n=read(),m=read(),k=read();
    vector<bool> is_friend(k+1,false);
    vector<int> first_add(n+1,0);
    int ans=0;
    for(int i=1;i<=n;i++)
        v[read()]=true;
    for(int i=1;i<=m;i++)
    {
        int begin=read(),end=read();
        if (is_friend[begin]==true&&is_friend[end]==true)
            ans++;
        else
        {
            if ((is_friend[begin]==true&&is_friend[end]==false)||(is_friend))
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //t=read();
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2025/10/18.
//