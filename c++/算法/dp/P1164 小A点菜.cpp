#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,N=101,M=10000+5;
int num[N][M];
void solve()
{
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for (int i = 1; i < n+1; i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < m+1; j++)
        {
            if(j-a[i]>0)
                num[i][j]=num[i-1][j]+num[i-1][j-a[i]];
            if(j==a[i])
                num[i][j]=num[i-1][j]+1;
            if(j<a[i]) num[i][j]=num[i-1][j];
        }
    }
    cout<<num[n][m]; 
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