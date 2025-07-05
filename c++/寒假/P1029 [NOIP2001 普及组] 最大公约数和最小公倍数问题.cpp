#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
int n,m,ans=0,biaoj;
void solve()
{
    cin>>n>>m;
    for(int i=n;i<=sqrt(1ll*n*m);i++)
    {
        ll a=i;
        ll b=(1ll*n*m)/a;
        if (__gcd(a,b)==n&&a/__gcd(a,b)*b==m&&a*b==(1ll*n*m))
        {
            ans++;
            if(a==b&&a*a==(1ll*n*m))
                biaoj=1;
        }    
    }
    cout<<ans*2-biaoj;
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