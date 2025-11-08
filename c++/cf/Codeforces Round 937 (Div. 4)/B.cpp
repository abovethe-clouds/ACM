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
    int n;
    cin >> n;
    char mp[2*n][2*n];
    for(int i=0;i<n;i++)
    {
        if (i%2==0)
        {
            for(int j=0;j<n;j++)
            {
                if (j%2==0) mp[i*2][j*2] = '#', mp[i*2+1][j*2] = '#', mp[i*2][j*2+1] = '#', mp[i*2+1][j*2+1] = '#';
                else mp[i*2][j*2] = '.', mp[i*2+1][j*2] = '.', mp[i*2][j*2+1] = '.', mp[i*2+1][j*2+1] = '.';
            }

        }
        else
        {
            for(int j=0;j<n;j++)
            {
                if (j%2) mp[i*2][j*2] = '#', mp[i*2+1][j*2] = '#', mp[i*2][j*2+1] = '#', mp[i*2+1][j*2+1] = '#';
                else mp[i*2][j*2] = '.', mp[i*2+1][j*2] = '.', mp[i*2][j*2+1] = '.', mp[i*2+1][j*2+1] = '.';
            }
        }
    }
    for(int i=0;i<2*n;i++)
    {
        for(int j=0;j<2*n;j++)
        {
            cout<<mp[i][j];
        }
        cout<<endl;
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
    cin>>t;
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2025/10/3.
//