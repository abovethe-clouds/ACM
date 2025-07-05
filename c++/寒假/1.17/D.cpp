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

void solve()
{
    ull a,b,c,d,s;
    cin>>s>>a>>b>>c>>d;
    ull he=s/a+s/b+s/c+s/d;
    ull jian=s/(a*b)+s/(a*c)+s/(a*d)+s/(b*c)+s/(b*d)+s/(d*c)-s/(a*b*c)-s/(d*b*c)+s/(a*b*c*d);
    cout<<he-jian;
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