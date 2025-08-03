#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=3e5+5;

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
int a[maxn], b[maxn];
void solve()
{
    int n, m,sum=0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] %= m;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i] %= m;
    }
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++)
    {
        auto u = lower_bound(b, b + n, m - a[i]);
        cout << *u <<" "<<a[i]<< endl;
        sum += (*u + a[i]) % m;
        *u = 0;
    }
    cout << sum << endl;
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
    cin >> t;
    while(t--)
        solve();

    return 0;
}