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
vector<int> pow_2(64);
void solve()
{
    int l,r,c;
    cin>>l>>r>>c;

}
void pow()
{
    pow_2[0]=1;
    for (int i=1;i<64;i++)
    {
        pow_2[i]=pow_2[i-1]*2;
    }
}
signed main()
{
    pow();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}
