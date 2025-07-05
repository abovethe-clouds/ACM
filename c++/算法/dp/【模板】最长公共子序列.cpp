#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131 , maxn=1e4+5;
int n,dp[maxn][maxn],a[maxn],b[maxn];
void solve1()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin>>b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    cout<<dp[n][n];
}
void solve2()
{
    cin>>n;
    map<int,int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];mp[a[i]]=i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin>>b[i];
    }
    int f[n+1]={},r=1;
    f[1]=mp[b[1]];
    for (int i = 2; i <= n; i++)
    {
        if(mp[b[i]]>f[r])
            f[++r]=mp[b[i]];
        else
            *lower_bound(f+1,f+r+1,mp[b[i]])=mp[b[i]];
    }
    cout<<r;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    while(t --)
        solve2();

    return 0;
}