#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int long long
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n),pre(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    vector<vector<int>> dp(n+1,vector<int>(k+1,inf));
    pre[0]=a[0];
    for(int i=1;i<n;i++)
    {
        pre[i]=pre[i-1]+a[i];
    }
    st_table st(a);




}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    while (t--)
        solve();
    return 0;
}
