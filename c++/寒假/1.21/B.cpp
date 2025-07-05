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
unordered_map<string,int> p;
void solve()
{
    int a;
    cin>>a;
    for (int i = 0; i < a*2-1; i++)
    {
        string s;
        cin>>s;
        if(p[s])
            p.erase(s);
        else
            p[s]++;
    }
    for (auto i:p)
    {
        if(i.second==1)
        {
           cout<<i.first;
           return; 
        }    
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