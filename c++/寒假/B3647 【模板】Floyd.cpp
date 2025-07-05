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
int tu[101][101],n,m;
void floyd()
{
    for (int k = 1; k <= n; k++)//中继点
    {
        for (int i = 1; i <= n; i++)//起点
        {
            for (int j = 1; j <= n; j++)//终点
            {
                tu[i][j]=min(tu[i][j],tu[i][k]+tu[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<tu[i][j]<<" ";
        cout<<endl;
    }    
    
    return;
}
void solve()
{
    cin>>n>>m;
    memset(tu,inf,sizeof(tu));
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        tu[a][b]=min(c,tu[a][b]);
        tu[b][a]=min(c,tu[a][b]);
    }
    for (int i = 1; i <= n; i++)
    {
        tu[i][i]=0;
    }
    floyd();

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