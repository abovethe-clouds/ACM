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
int n,a[100001];
void solve()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n%2==0)
    {
        cout<<a[n/2+1]-a[n/2];
    }
    else
        cout<<0;
    
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