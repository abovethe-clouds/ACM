#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=1e8+5;
bool isprime[maxn];
int prime[maxn],prim=1;
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i < maxn; i++)
    {
        isprime[i]=1;
    }
    for (int i = 2; i < maxn; i++)
    {
        if(isprime[i])
        {
            prime[prim++]=i;
        }
        for (int j = 1; j < prim && i * prime[j] < maxn; j++)
        {
            isprime[i*prime[j]]=0;
            if(i%prime[j]==0)
                break;
        }
    }
    
    for (int i = 1; i <= m; i++)
    {
        int a;
        cin >> a;
        cout << prime[a] << endl;
    } 
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
