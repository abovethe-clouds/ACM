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
ll f[10000001],w[10001],v[10001],m,n;
void solve()
{
    cin>>m>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>w[i]>>v[i];
    }
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(w[i]<=j)
                f[j]=max(f[j],f[j-w[i]]+v[i]);
    cout<<f[m];
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