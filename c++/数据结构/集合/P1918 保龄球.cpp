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
map<int,int> a;
void solve()
{
    int n,m;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        int s;
        cin>>s;
        a[s]=i;
    }
    cin>>m;
    for (int i = 1; i <= m; i++)
    {
        int s;
        cin>>s;
        if(a.count(s))
            cout<<a[s]<<endl;
        else
            cout<<"0"<<endl;

    }
    return;
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