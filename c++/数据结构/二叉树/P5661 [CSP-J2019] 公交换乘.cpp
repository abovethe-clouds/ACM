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
vector <pii> s,b;
void solve()
{
    int n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        if(d==0)//subway
        {
            int t,p;
            cin>>t>>p;
            s.push_back(make_pair(t,p));
            sum+=p;
        }
        else//bus
        {
            int t,p;
            cin>>t>>p;
            b.push_back(make_pair(t,p));
        }
    }
    while (!b.empty())
    {
        
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