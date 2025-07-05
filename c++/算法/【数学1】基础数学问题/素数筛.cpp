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
bool isprime[1000000];
int prime[100000],prim=1;
void solve()
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
    for (int i = 1; i < 10000; i++)
    {
        cout<<prime[i]<<",";
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
