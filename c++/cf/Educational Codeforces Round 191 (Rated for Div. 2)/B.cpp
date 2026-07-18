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
    int n;
    cin>>n;
    if (n==2)
    {
        cout<<"1 1 2 1 2 2 1 2"<<endl;
        return;
    }
    if (n==3)
    {
        cout<<"1 1 2 1 2 3 1 3 2 2 3 3"<<endl;
        return;
    }
    for (int i=1;i<=4;i++)
    {
        for (int j=i;j<=n;j++)
        {
            cout<<j<<" ";
        }
        for (int j=1;j<i;j++)
        {
            cout<<j<<" ";
        }
    }
    cout<<endl;
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
    cin>>t;
    while (t--)
        solve();
    return 0;
}
