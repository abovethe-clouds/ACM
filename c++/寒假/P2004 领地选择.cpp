#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int N = 1e5, M = N * 2, mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
ll s[1002][1002],a[1002][1002],n,m,max1=-inf,c,xxx,yyy;
void solve()
{
    cin>>n>>m>>c;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
        }
    }
    for (int x1=c;x1<=n;x1++)
    {
        for (int y1=c;y1<=m;y1++)
        {
            int x2=x1-c;
            int y2=y1-c;
            int ans=s[x1][y1]-s[x1][y2]-s[x2][y1]+s[x2][y2];
            if(ans>max1)
            {
                xxx=x2;
                yyy=y2;
                max1=ans;
            }
        }
    } 
    cout<<xxx+1<<" "<<yyy+1;
    return;  
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