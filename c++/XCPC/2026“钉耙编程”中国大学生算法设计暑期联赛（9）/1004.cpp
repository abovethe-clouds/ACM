#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
vector<int> base(61);
void ins(int x)
{
    for (int i=60;i>=0;i--)
    {
        if (x&(1ll<<i))
        {
            if (!base[i])
            {
                base[i]=x;
                return;
            }
            x^=base[i];
        }
    }
}
void solve()
{
    fill( base.begin(),base.end(),0);
    int n,len,q;
    cin>>n>>len>>q;
    vector<int> arr(n);
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=0;
    for (int i=0;i<len;i++)
    {
        ans^=arr[i];
    }
    ins(ans);
    for (int i=len;i<n;i++)
    {
        ans^=arr[i-len];
        ans^=arr[i];
        ins(ans);
    }
    while (q--)
    {
        int x;
        cin>>x;
        int t=x;
        x=~x;
        ans=0;
        for (int i=60;i>=0;i--)
        {
            if ((x&(1ll<<i))&&base[i])
            {
                x^=base[i];
                ans^=base[i];
            }
        }
        cout<<(ans^t)<<endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2026/7/24.
//