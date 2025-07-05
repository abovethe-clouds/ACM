#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int N = 1e5, M = N * 2, mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
map<ll,ll> rem;
ll f(ll x)
{
    if(rem.find(x) != rem.end())
        return rem[x];
    if(x==1)
        return rem[x]=1;
    else
        return rem[x]=2*f(x/2)+1;
}
ll H,cnt,x=1;
void solve()
{
    cin>>H;
    f(H);
    cout<<rem[H];
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