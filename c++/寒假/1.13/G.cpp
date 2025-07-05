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
int money[6]={100,50,10,5,2,1},cnt=0;
void solve()
{
    int pay;
    cin>>pay;
    for (int i = 0; i < 6; i++)
    {
        if(pay>=money[i])
        {
            cnt+=pay/money[i];
            pay%=money[i];
        }
    }
    
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
    cout<<cnt;
    return 0;
}