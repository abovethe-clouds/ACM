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
    const int n=read(),m=read(),k=read();
    int mp[k];
    for(int i=0;i<k;i++)
        mp[i]=read();
    ll ans=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            int a=read();
            int l=0;
            for (int o=0;o<k;o++)
            {
                if (mp[o]==a)
                    l=o;
            }
            ans+=l+1;
            for(int o=l;o>0;o--)
            {
                mp[o]=mp[o-1];
            }
            mp[0]=a;
        }
    cout<<ans<<endl;
}

int main()
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
