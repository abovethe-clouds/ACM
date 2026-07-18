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
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++)
        cin>>v[i];
    vector<int> v2 = v;
    int ans1=0, ans2=0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i]!=v[n-i+1])
        {
            int x=abs(v[i]-v[n-i+1]);
            if (v[i]>v[n-i+1])
            {
                v[i]=v[n-i+1];
                if (v[i+1]>v[n-i])
                {
                    v[i+1]=max(v[i+1]-x,v[n-i]);
                }
            }
            else
            {
                v[i]=v[n-i+1];
                if (v[i+1]<v[n-i])
                {
                    v[i+1]=min(v[i+1]+x,v[n-i]);
                }
            }
            ans1+=x;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (v2[i]!=v2[n-i+1])
        {
            int x=abs(v2[i]-v2[n-i+1]);
            if (v2[i]>v2[n-i+1])
            {
                v2[i]=v2[n-i+1];
                if (v2[i+1]>v2[n-i])
                {
                    v2[i+1]=max(v2[i+1]-x,v2[n-i]);
                }
            }
            else
            {
                v2[i]=v2[n-i+1];
                if (v2[i+1]<v2[n-i])
                {
                    v2[i+1]=min(v2[i+1]+x,v2[n-i]);
                }
            }
            ans2+=x;
        }
    }
    cout<<min(ans1,ans2);
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
