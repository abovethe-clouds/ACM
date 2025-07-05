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
    string s;
    cin>>s;
    for(int a=s.length()-1;a>=0;a--)
    {
        auto i=s[a];
        if(i=='q')
            cout<<"p";
        else if(i=='p')
            cout<<"q";
        else
            cout<<"w";
    }
    cout<<endl;

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