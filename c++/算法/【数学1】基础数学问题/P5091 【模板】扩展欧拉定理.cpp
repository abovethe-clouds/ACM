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
ll fast_pow(ll x,ll y,ll mod)
{
    ll ans = 1;
    while (y)
    {
        if(y%2)
        {
            ans = ans * x % mod;
        }
        y /= 2;
        x = x * x % mod;
    }
    return ans;
}
int oula(int x)
{
    int phi = x;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            phi /= i;
            phi *= i - 1;
            while (x % i==0)
            {
                x /= i;
            }
        }
    }
    if (x > 1)
        phi = phi / x * (x - 1);
    return phi;
}
ll exponent(string s, ll phi)
{
    string p = to_string(phi);
    ll exp = 0;
    if(s.length()<=p.length())
    {
        for (auto i : s)
        {
            exp = exp * 10 + (i - '0');
        }
        return exp;
    }
    for (auto i : s)
    {
        exp = exp * 10 + (i - '0');
        if(exp>=phi)
            exp %= phi;
    }
    return exp + phi;
}
void solve()
{
    ll a, m;
    string s;
    cin >> a >> m >> s;
    cout << fast_pow(a, exponent(s, oula(m)), m);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        // freopen("test.in", "r", stdin);
        // freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
}