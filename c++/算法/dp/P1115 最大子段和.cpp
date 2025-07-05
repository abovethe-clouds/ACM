#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn=1e5+5;
void solve()
{
    int n,max1=-inf;
    cin>>n;
    int a[n]={},b[n]={};
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(i==0)
            b[i]=a[i];
        else
            b[i]=max(a[i],b[i-1]+a[i]);
        max1=max(max1,b[i]);
    }
    cout<<max1;
        
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