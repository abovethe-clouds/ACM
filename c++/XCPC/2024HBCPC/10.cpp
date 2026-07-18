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
    int m;
    cin>>m;
    vector<int> a(10);
    for(int i=0;i<10;i++)
        cin>>a[i];

    int ans=0;
    for (int i=1;i<10;i++)
    {
        if (a[i]!=0)
        {
            ans=i;m--;
            a[i]--;
            break;
        }
    }
    for (int i=0;i<10;i++)
    {
        if (a[i]!=0)
        {
            if (a[i]<=m)
            {
                m-=a[i];
                for (int j=0;j<a[i];j++)
                {
                    ans*=10;
                    ans+=i;
                    ans%=mod;
                }
            }
            else
            {
                for (int j=0;j<m;j++)
                {
                    ans*=10;
                    ans+=i;
                    ans%=mod;
                }
                m=0;
                break;
            }
        }
    }
    cout<<ans<<endl;
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
//
// Created by Administrator on 2026/5/21.
//