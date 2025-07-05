#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int N = 1e5, M = N * 2, mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
string s;
int cnt=0;
void solve()
{
    cin>>s;
    int i=-1,j=s.length();
    while(i!=j&&i+1!=j)
    {
        i++;
        j--;
		if(s[i]!=s[j])
            cnt++;
        
    }
    cout<<cnt;
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