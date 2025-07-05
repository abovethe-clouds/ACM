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
                tu[i][j]=(tu[i][j]||tu[i][k]&&tu[k][j]);
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
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>tu[i][j];
        }
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