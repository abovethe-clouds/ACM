#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int long long
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 10000007, inf = 0x3f3f3f3f, P = 131;
int dp[64][2][64][64] = {};
int ans[64];
int read()
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
int n,a[64],cnt=0;
int dfs(int i,int free,int fill_1,int sum_1)
{
    // if (fill_1>sum_1)
    //     return 0;
    if (i==0)
        return fill_1==sum_1 ? 1 : 0;
    if (dp[i][free][fill_1][sum_1]!=-1)
        return dp[i][free][fill_1][sum_1];
    int up=free?1:a[i];
    int sum=0;
    for (int j = 0; j <= up; ++j)
    {
        if (j==0)
            sum+=dfs(i-1, free || (j < a[i]),fill_1,sum_1);
        else
            sum+=dfs(i-1,free,fill_1+1,sum_1);
    }
    return dp[i][free][fill_1][sum_1]=sum;
}
int fast_pow(int a, int b, int p)
{
    a %= p;
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % p;
        }
        a = a * a % p;
        b /= 2;
    }
    return ans;
}
void solve()
{
    while (n)
    {
        a[++cnt]=n&1;
        n>>=1;
    }
    memset(dp,-1,sizeof(dp));
    for (int i = 1; i <= cnt; i++)
    {

        ans[i]=dfs(cnt,0,0,i);
    }
    ll ans1=1;
    for (int i = 1; i <= 50; i++)
        ans1=ans1*fast_pow(i,ans[i],mod)%mod;
    cout<<ans1<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    solve();
    return 0;
}
