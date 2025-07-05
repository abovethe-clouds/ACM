#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int  mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
int n,m,a[1000],u[1000],j;
void solve()
{
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin>>u[i];
    }
    for (int i = 0; i < m; i++)
    {
        j++;
        sort(a,a+u[i]);
        cout<<a[j-1]<<endl;
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