#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 998244353, inf = 0x3f3f3f3f, P = 131;
int zuhe(int n,int m)
{
    if(n==0||n==m)
        return 1;
    if(m==0)
        return 0;
    return (zuhe(n-1,m-1)%mod+zuhe(n,m-1)%mod)%mod;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int cnt=0;
    for (int i = 0; i < n-1; i++)
    {
        if(a[i]>a[i+1])
            cnt++;
    }
    cout<<zuhe(m-cnt,n-2-cnt)<<endl;
    
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t --)
        solve();

    return 0;
}