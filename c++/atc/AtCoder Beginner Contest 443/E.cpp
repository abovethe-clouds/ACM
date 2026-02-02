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
int dx[3]={-1,-1,-1};
int dy[3]={0,1,-1};
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
    int n,c;
    cin>>n>>c;
    bool mp[n][n];
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for (int j=0;j<n;j++)
        {
            if (s[j]=='#')
                mp[i][j]=1;//1代表障碍物
            else
                mp[i][j]=0;
        }
    }
    for (int i=0;i<n;i++)
    {
        if (!mp[n-1][i])
        {
            for ()
        }

    }
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
    cin>>t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2026/1/31.
//