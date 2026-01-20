#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
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
    int n = read();
    bool judge[1<<n] = {false};
    cout<<(1<<n)-1<<" ";
    judge[(1<<n)-1] = true;
    int now=(1<<n)-1;
    for (int i=n-1;i>=0;i--)
    {
        now^=(1<<i);
        cout<<now<<" ";
        judge[now]=true;
        for (int j=0;j<1<<(n-i);j++)
        {
            int to=max(((j<<i)-1),0)|now;
            if (!judge[to])
            {
                cout<<to<<" ";
                judge[to]=true;
            }
        }
    }
    for (int i=0;i<(1<<n);i++)
    {
        if (!judge[i])
            cout<<i<<" ";
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
// Created by Administrator on 2026/1/20.
//