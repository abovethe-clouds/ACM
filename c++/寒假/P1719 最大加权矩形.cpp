#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second  
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int N = 1e5, M = N * 2, mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
int s[121][121],a[121][121],n,m,max1=0;
void solve()
{
    cin>>n;
    m=n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
        }
    }
    for (int x1=1;x1<=n;x1++)
    {
        for (int y1=1;y1<=m;y1++)
        {
            for (int x2=1;x2<=x1;x2++)
            {
                for (int y2=1;y2<=y1;y2++)
                {
                    int ans=s[x1][y1]-s[x1][y2-1]-s[x2-1][y1]+s[x2-1][y2-1];
                    max1=max(max1,ans);
            	}
            } 
        }
    } 
    cout<<max1;
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