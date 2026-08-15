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

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int cnt = 1;
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            cnt++;

    for (int i=3;i<n;i++)
    {
        if (a[i-3]==a[i-2]&&a[i-2]!=a[i-1]&&a[i-1]==a[i])
        {
            cout<<cnt+2<<endl;
            return;
        }
    }
    for(int i=2;i<n;i++)
    {
        if(a[i-2]==a[i-1] && a[i-1]!=a[i])
        {
            if(i+1==n || a[i+1]!=a[i-1])
            {
                cout<<cnt+1<<endl;
                return;
            }
        }
        if(a[i-2]!=a[i-1] && a[i-1]==a[i])
        {
            if(i-2==0 || a[i-2-1]!=a[i-1])
            {
                cout<<cnt+1<<endl;
                return;
            }
        }
    }
    cout<<cnt<<endl;
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
// Created by Administrator on 2026/8/7.
//