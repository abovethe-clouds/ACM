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
int a[1001][1001],dp[1001][1001];
void solve()
{
    
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin>>a[i][j];
        }
    }
    for (int i = n; i >= 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i][j]=a[i][j]+max(dp[i+1][j+1],dp[i+1][j]);
        }    
    }
    cout<<dp[1][1];
    
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