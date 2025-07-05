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
vector<ll> a;
void solve()
{
    int n;
    cin>>n;
    while (n--)
    {
        int x,y;
        cin>>x>>y;
        a.push_back(y);
    }
    sort(a.begin(),a.end());
    int l=a.size();
    ll c;
    if(l%2==0) 
        c=(a[l/2-1]+a[l/2])/2;
    else
        c=a[(l-1)/2];
    ll sum=0;
    for (int i = 0; i < a.size(); i++)
    {
        sum+=abs(c-a[i]);
    }
    cout<<sum;
    
    
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