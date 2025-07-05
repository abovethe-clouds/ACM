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
ll w,p;
ll fast_pow(ll a,ll b,ll p)
{
    a%=p;
    ll ans=1;
    while (b)
    {
        if(b&1)
        {
            ans=ans*a%p;
        }
        a=a*a%p;
        b/=2;
    }
    return ans;
}
void solve()
{
    cin>>w>>p;
    for (int i = 1; i < w+1; i++)
    {
        cout<<fast_pow(i,p-2,p)<<endl;
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
}