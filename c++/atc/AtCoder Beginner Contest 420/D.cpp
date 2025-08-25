#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
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
    int H,W;
    cin>>H>>W;
    char mp[H][W];
    int bx,by,ex,ey;
    for (int i = 0; i < H; i++)
    {
        string s;
        cin>>s;
        for (int j = 0; j < W; j++)
        {
            mp[i][j]=s[j];
            if (mp[i][j]=='S')
            {
                bx=i;
                by=j;
            }
            else if (mp[i][j]=='G')
            {
                ex=i;
                ey=j;
            }
        }
    }
    bool vis[H][W]={};


}

int main()
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
// Created by Administrator on 2025/8/24.
//