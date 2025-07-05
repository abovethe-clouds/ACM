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
pii a[100001];int sum=0;
void solve()
{
    int n,m;
    cin>>n>>m;
    
    for (int i = 1; i <= m; i++)
    {
        int m;string s;
        cin>>m>>s;
        if(a[m].second==0&&s=="WA")
        {
            a[m].first++;
        }
        if(s=="AC")
        {
            a[m].second=1;
        }
    }
    int cnt=0;
    for (int i = 1; i <= n; i++)
    {
        if(a[i].second==1)
        {
            sum+=a[i].first;
            cnt++;
        }
               
    }
    cout<<cnt<<" "<<sum;
    
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