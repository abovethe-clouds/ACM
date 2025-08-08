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
    int a,ta,b,tb,hh,mm;
    scanf("%d %d",&a,&ta);
    scanf("%d %d",&b,&tb);
    scanf("%d:%d",&hh,&mm);
    int time_begin=hh*60+mm;
    int time_end=time_begin+ta;
    int ans=0;
    for (int i=5*60;i<24*60;i+=b)
    {
        int y2 = i + tb;
        int x = max(time_begin, i), y = min(time_end, y2);
        if (x < y)
            ans++;
    }
    cout << ans << endl;
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
