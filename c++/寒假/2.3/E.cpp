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
int fast_pow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b%2==1)
        {
            ans*=a;
        }
        a=a*a;
        b/=2;
    }
    return ans;
}
void solve()
{
    int k,l1,r1,l2,r2;
    cin>>k>>l1>>r1>>l2>>r2;
    int ans=0;
    for (int i = l1; i <= r1; i++)
    {
        k=INT_MAX;
        for (int j = log(l2)/(log(l1)); j <= k; j++)
        {
            if(fast_pow(i,j)>=l2&&fast_pow(i,j)<=r2)
                ans++;
            if(fast_pow(i,j)>r2)   
            {
                k=j;
                break;
            }
        }
        
    }
    cout<<ans<<endl;
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