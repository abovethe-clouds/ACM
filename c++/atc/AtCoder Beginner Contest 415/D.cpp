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
struct D
{
    unsigned long long a, b, c;
};
bool cmp(D a,D b)
{
    if(a.c!=b.c)
    {
        return a.c < b.c;
    }
    return a.a < b.a;
}
void solve()
{
    unsigned long long n, m;
    cin >> n >> m;
    D a[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].a >> a[i].b;
        a[i].c = a[i].a - a[i].b;
    }
    sort(a, a + m, cmp);
    unsigned long long cnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (n >= a[i].a)
        {
            unsigned long long ne = (n - a[i].a) / a[i].c;
            n -= ne * a[i].c;
            cnt += ne;
            while (n >= a[i].a) // n-?*a[i].c>=a[i].a
            {
                n -= a[i].c;
                cnt++;
            }
        }
    }
    cout << cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        //freopen("test.in", "r", stdin);
       // freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    while(t--)
        solve();

    return 0;
}