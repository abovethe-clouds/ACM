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
struct matrix
{
    int n;
    vector<vector<ll>> dp;
    matrix(int x) : n(x), dp(x + 1, vector<ll>(x + 1)) {};
};
matrix operator*(const matrix &a, const matrix &b)
{
    int n = a.n;
    matrix c(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                c.dp[i][j] = (c.dp[i][j] + a.dp[i][k] * b.dp[k][j] % mod) % mod;
            }
        }
    }
    return c;
}
matrix fast_pow(matrix a,ll exp)
{
    int n = a.n;
    matrix ans(n);
    for (int i = 0; i <= n;i++)
    {
        ans.dp[i][i] = 1;
    }
    while (exp)
    {
        if(exp%2)
        {
            ans = ans * a;
        }
        exp /= 2;
        a = a * a;
    }
    return ans;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    matrix a(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n;j++)
        {
            cin >> a.dp[i][j];
        }
    }
    matrix o = fast_pow(a, k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << o.dp[i][j] << " ";
        }
        cout << endl;
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        //freopen("test.in", "r", stdin);
       // freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    while(t--)
        solve();

    return 0;
}