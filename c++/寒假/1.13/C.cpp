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
priority_queue<ll> road;
ll vis[200000];
void solve()
{
    int c,n;
    cin>>c>>n;
    for (ll i = 0; i < n; i++)
    {
        cin>>vis[i];
    }
    for (ll i = 1; i < n; i++)
    {
        road.push(vis[i]-vis[i-1]);
    }
    road.push(c-vis[n-1]+vis[0]);
    cout<<c-road.top();
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