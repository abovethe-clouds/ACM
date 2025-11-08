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
    int  s1;string s2;
    cin>>s1>>s2;
    vector<int> next(s2.length()+1);
    next[0]=-1,next[1]=0;
    {
        int i=2,cn=0;
        while(i<=s1)
        {
            if(s2[i-1]==s2[cn])
            {
                next[i++]=++cn;
            }
            else if(cn>0)
            {
                cn=next[cn];
            }
            else
            {
                cn=0;
                next[i++]=cn;
            }
        }
    }
    cout<<s1-next[s1];
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
