#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
//typedef long long ll;
typedef unsigned long long ull;
#define int long long
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
    const int n = read(),m=read();
    int a[n+1]={},maxx=0,sum[n+1]={};

    for(int i=1;i<=n;i++)
    {
        a[i] = read();
        maxx = max(maxx,a[i]);
    }
    sort(a,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i] = sum[i-1] + a[i];
    for (int i = 1; i <= m; i++)
    {
        int x = read();
        if (x > maxx)
        {
            cout << -1 << endl;
            continue;
        }
        int where=upper_bound(a,a+n,x-1)-a;
        int ans=sum[where-1];
        ans+=(n-where+1)*(x-1);
        cout << ans+1 << endl;
    }



}

signed main()
{

#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
