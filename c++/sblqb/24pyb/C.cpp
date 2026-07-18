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
    int n,m;
    cin>>n>>m;
    int ans=0;
    vector mp(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>mp[i][j];
    }
    for (int l=1;l<min(n,m);l++)
    {
        for(int i=0;i<n-l;i++)
        {
            for(int j=0;j<m-l;j++)
            {
                if (mp[i][j]==mp[i+l][j+l])
                    ans++;
                if (mp[i][j+l]==mp[i+l][j])
                    ans++;

            }
        }
    }
    cout<<ans*2<<endl;
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
