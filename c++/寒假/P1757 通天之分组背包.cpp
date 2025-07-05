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
int w[1001][1001],v[1001][1001];
int f[1001][1001],m,n,zu;
void solve()
{
    cin>>m>>n;
    for (int i = 1; i <= n; i++)
    {
        int z1,w1,v1;
        cin>>w1>>v1>>z1;
        w[z1][++w[z1][0]]=w1;
        v[z1][++v[z1][0]]=v1;
        zu=max(zu,z1);
    }
    for(int i=1;i<=zu;i++)//组数
        for(int j=m;j>=0;j--)
        {
            f[i][j]=max(f[i][j],f[i-1][j]);
            for(int k=1;k<=w[i][0];k++)
                if(w[i][k]<=j)
                {
                    f[i][j]=max(f[i][j],f[i-1][j-w[i][k]]+v[i][k]);
                }
             
        }
                
    cout<<f[zu][m];    
    
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