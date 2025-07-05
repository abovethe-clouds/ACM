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
    ll a,b;
    string s;
    cin>>a>>b>>s;
    if(((a>0&&b>0)||(b<0&&a<0))&&(s=="yes"||s=="Yes"||s=="yEs"||s=="yeS"||s=="YEs"||s=="YeS"||s=="yES"||s=="YES"))
        cout<<"ok";
    else
    {
        if(((a>0&&b<0)||(b>0&&a<0))&&(s=="no"||s=="No"||s=="nO"||s=="NO"))
        cout<<"ok";
        else
            cout<<"wa";
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