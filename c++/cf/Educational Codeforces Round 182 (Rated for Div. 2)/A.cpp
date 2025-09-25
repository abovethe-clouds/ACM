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
    const int N=read();
    vector<int> v(N+1),sum(N+1);
    for(int i=1;i<=N;i++)
    {
        v[i]=read();
        sum[i]=sum[i-1]+v[i];
    }
    for (int i=1;i<=N;i++)
        for (int j=i+1;j<=N;j++)
        {
            if ((sum[i]%3==(sum[j]-sum[i])%3&&(sum[j]-sum[i])%3==(sum[N]-sum[j])%3)||((sum[i]%3!=(sum[j]-sum[i])%3&&(sum[j]-sum[i])%3!=(sum[N]-sum[j])%3&&(sum[N]-sum[j])%3!=sum[i]%3)))
            {
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    cout<<"0 0"<<endl;
    return;
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
// Created by Administrator on 2025/9/16.
//