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

void solve()
{
    ll a,b,n,sum;int i;
    cin>>a>>b>>n;
    for(i=1;sum<=n;i++)
    {
        int j=i%7;
        if(j>0&&j<=5)
            sum+=a;
        else
            sum+=b;
    }
    cout<<i-1;
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