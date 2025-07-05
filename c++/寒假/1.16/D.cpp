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
int zuhe(int n,int m)
{
    if(n==0||n==m)
        return 1;
    return zuhe(n-1,m-1)+zuhe(n,m-1);
}
void solve()
{
    int a,b;
    cin>>a>>b;
    cout<<zuhe(b,a);
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