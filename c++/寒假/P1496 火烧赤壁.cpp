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
    int n;
    cin>>n;
    int a[n],b[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    int l=0;
    for (int i = 0; i < n; i++)
    {
        l+=b[i]-a[i];
        if(i+1<n)
            if(b[i]>a[i+1])
                l-=b[i]-a[i+1];
    }
    cout<<l<<endl;
    return ;
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int t = 1;
    cin >> t;
    while(t --)
        solve();
 
    return 0;
}