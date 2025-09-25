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
    int cnt=0,sum=0,where_0=-1;
    vector<int> v(N);
    for (int i=0;i<N;i++)
    {
        v[i]=read();
        sum+=v[i];
        if (v[i]==0)
        {
            where_0=i;cnt++;
        }

    }
    if (cnt>=2)
    {
        int l=1, r=N;
        for (int i=0;i<N;i++)
        {
            if (v[i]!=i+1)
            {
                l=i;
                break;
            }
        }
        for (int i=N-1;i>=0;i--)
        {
            if (v[i]!=i+1)
            {
                r=i;
                break;
            }
        }
        cout<<r-l+1<<endl;
        return;
    }
    if (cnt==1)
    {
        v[where_0]=N*(N+1)/2-sum;
        int l=-1, r=-1;
        for (int i=0;i<N;i++)
        {
            if (v[i]!=i+1)
            {
                l=i;
                break;
            }
        }
        for (int i=N-1;i>=0;i--)
        {
            if (v[i]!=i+1)
            {
                r=i;
                break;
            }
        }
        cout<<(r==-1&&l==-1?0:r-l+1)<<endl;
        return;
    }
    int l=-1, r=-1;
    for (int i=0;i<N;i++)
    {
        if (v[i]!=i+1)
        {
            l=i;
            break;
        }
    }
    for (int i=N-1;i>=0;i--)
    {
        if (v[i]!=i+1)
        {
            r=i;
            break;
        }
    }
    cout<<(r==-1&&l==-1?0:r-l+1)<<endl;
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