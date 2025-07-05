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
map<string,int> q;
int n;
void solve()
{
    
    string w;
    int max1=0;
    while (n--)
    {
        string s;
        cin>>s;
        q[s]++;
    }
    for(auto p:q)
    {
        if(p.second>=max1)
        {
            max1=p.second;
            w=p.first;
        }
    }
    cout<<w<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(cin>>n)
    {
        if(n==0)
            return 0;
        else
            solve();
    }

    return 0;
}