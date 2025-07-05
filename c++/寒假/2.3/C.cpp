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
    int m,a,b,c;
    cin>>m>>a>>b>>c;
    int sum=0,k_1=m,k_2=m;
    sum+=min(a,k_1);
    k_1-=sum;
    sum+=min(b,k_2);
    k_2-=min(b,k_2);
    sum+=min(c,k_1+k_2);
    cout<<sum<<endl;
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