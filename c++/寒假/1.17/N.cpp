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
    int n,m;
    string s;
    cin>>n>>m>>s;
    n=s.length();
    int i=0,j=0,zero=0,max1=0;
    while(i<n&&j<n)
    {
        if(s[j]=='0') zero++;
        while(zero>m)
        {
        	if(s[i]=='0')
        		zero--;
        	i++;
		}
		max1=max(max1,j-i+1);
		j++;
        
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