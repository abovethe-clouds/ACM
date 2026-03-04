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
int n;
int dfs(vector<vector<int>>& mp, int x, int y)
{
    int minn = 0;
    while (x <= n && y <= n)
    {
        minn = min(minn, mp[x][y]);
        x++;
        y++;
    }
    return -minn;
}
void solve()
{
    n=read();
    vector<vector<int>> mp(n+1,vector<int>(n+1));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            mp[i][j]=read();
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        sum+=dfs(mp,i,1);
    }
    for (int i=2;i<=n;i++)
    {
        sum+=dfs(mp,1,i);
    }
    cout<<sum<<endl;
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
    t=read();
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2026/2/26.
//