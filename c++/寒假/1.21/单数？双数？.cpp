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
    while (n--)
    {
        string s;
        cin>>s;
        int l=s.length()-1;
        int a=(s[l]-'0');
        if(a%2==0)
        {
            cout<<"even"<<endl;
        }
        else
            cout<<"odd"<<endl;
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