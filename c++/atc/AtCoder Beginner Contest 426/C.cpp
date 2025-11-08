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
    const int n=read();
    vector<int> v(n+1,1);
    v[0]=0;
    int min_OS=0;
    int Q=read();
    while (Q--)
    {
        int x=read(),y=read();
        if (x<=min_OS)
        {
            cout<<"0"<<endl;
            continue;
        }
        int sum=0;
        for (int i=min_OS+1;i<=x;i++)
        {
            sum+=v[i];
        }
        cout<<sum<<endl;
        v[y]+=sum;
        min_OS=x;
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
// Created by Administrator on 2025/10/4.
//