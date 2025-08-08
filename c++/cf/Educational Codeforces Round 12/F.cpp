#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
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
bool isprime[1000000];
int prime[100000],prim=1;
void pr()
{
    for (int i = 1; i < 1000000; i++)
    {
        isprime[i]=1;
    }
    for (int i = 2; i < 1000000; i++)
    {
        if(isprime[i])
        {
            prime[prim++]=i;
        }
        for (int j = 1; j < prim&&i*prime[j]<1000000; j++)
        {
            isprime[i*prime[j]]=0;
            if(i%prime[j]==0)
                break;
        }
    }
}
void solve()
{
    pr();
    ll n;
    cin>>n;
    int ans=0;
    for(int i = 1; i < prim; i++)
    {
        if (prime[i]*1ll*prime[i]*prime[i]<=n)
            ans++;
    }
    for(int i = 1; i < prim; i++)
        for(int j = i+1; j < prim; j++)
        {
            if (prime[i]*1ll*prime[j]<=n)
                ans++;
            else
                break;
        }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
