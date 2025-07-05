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
double w,h,x,y;
void solve()
{
    cin>>w>>h>>x>>y;
    printf("%.6f ",w*h/2);
    if(x==w/2&&y==h/2)
        cout<<1;
    else
        cout<<0;
}
int main()
{
    
    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
}