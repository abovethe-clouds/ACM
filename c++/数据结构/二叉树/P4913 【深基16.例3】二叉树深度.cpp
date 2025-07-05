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
struct node
{
    int left,right;
};
node a[1000005];
int dfs(int x)
{
    if(!x) return 0;
    else return (max(dfs(a[x].left),dfs(a[x].right))+1);
}
void solve()
{
    
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i].left>>a[i].right;
    }
    cout<<dfs(1);
    
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