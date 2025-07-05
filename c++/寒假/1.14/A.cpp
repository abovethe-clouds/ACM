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
int a[50];
int n,cnt;
void dfs(int sum1,int sum2,int x)
{
    if(x==n)
    {
        if(sum1==sum2)
            cnt++;
    }
    else
    {
        sum1+=a[x];
        dfs(sum1,sum2,x+1);
        sum1-=a[x];
        sum2+=a[x];
        dfs(sum1,sum2,x+1);
    }
    return;
}
void solve()
{
    
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    dfs(0,0,0);
    cout<<cnt/2;
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