#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int N = 1e5, M = N * 2, mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
ll fast_pow(ll a,ll b,ll c)
{
    long long ans=1;
    while(b)
    {
        if(b%2==1)
        {
            ans*=a;
            ans%=c;
        }
        a=a*a%c;
        b/=2;
    }
    return ans;
}
void solve()
{
    ll a,b,c;
    cin>>a>>b>>c;
    printf("%d^%d mod %d=%d",a,b,c,fast_pow(a,b,c));
}
int main()
{

    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
}