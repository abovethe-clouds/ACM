#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
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
    int n = read(),k=read(),q=read();
    vector<int> a(k+1),b(k+1);
    a[0]=0,b[0]=0;
    for(int i=1;i<=k;i++)
        a[i]=read();
    for(int i=1;i<=k;i++)
        b[i]=read();
    while(q--)
    {
        int w=read();
        int where=lower_bound(a.begin(),a.end(),w)-a.begin();
        if (a[where]==w)
        {
            cout<<b[where]<<" ";
            continue;
        }
        where--;
        int l=a[where+1]-a[where];
        int time=b[where+1]-b[where];

        cout<< (b[where] + (((w - a[where]) * time / l)))<<" ";
    }
    cout<<endl;
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
