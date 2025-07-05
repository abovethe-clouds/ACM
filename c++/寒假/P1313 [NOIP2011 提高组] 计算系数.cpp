#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int N = 1e5, M = N * 2,  inf = 0x3f3f3f3f, P = 131,mod=10007;
int jiyi[1000][1000];
int zuhe(int n,int m)
{
    if(jiyi[n][m]!=-1)
        return jiyi[n][m];
    if(n==0||n==m)
    {
        jiyi[n][m]=1;
        return jiyi[n][m];
    }    
    jiyi[n][m]=(zuhe(n-1,m-1)%mod+zuhe(n,m-1)%mod)%mod;
    return jiyi[n][m];    
    
}
ll fast_pow(ll a,ll b)
{
    ll c=mod;
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
    ll a,b,k,n,m;
    cin>>a>>b>>k>>n>>m;
    cout<<(fast_pow(a,n)%mod*fast_pow(b,m)%mod*zuhe(n,k)%mod)%mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(jiyi,-1,sizeof(jiyi));
    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
}