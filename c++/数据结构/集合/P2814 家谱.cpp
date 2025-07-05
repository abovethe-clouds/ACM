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
map<string,string> q;
char op;string s,s1;
string find(string s)
{
    if(q.find(s)!=q.end())
        return find(q[s]);
    else
        return s;
}
void solve()
{
    while(cin>>op)
    {
        if(op=='#')//father
        {
            cin>>s1;
        }
        if(op=='+')
        {
            cin>>s;
            q[s]=s1;
        }
        if(op=='?')
        {
            cin>>s;
            cout<<s<<" "<<find(s)<<endl;
        }
        if(op=='$')
            return;
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