#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
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
    for (int i = 2; i <= n; i++)
    {
        cout<<"? "<<i*2<<" "<<i*2-1<<endl;
        int x;
        cin>>x;
        if (x==1)
        {
            cout<<"! "<<i*2<<endl;
            return;
        }
    }
    int x,y;
    cout<<"? 1 3"<<endl;
    cin>>x;
    cout<<"? 1 4"<<endl;
    cin>>y;
    if (x==1||y==1)
    {
        cout<<"! "<<1<<endl;
    }
    else
    {
        cout<<"! 2"<<endl;
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
// Created by Administrator on 2026/7/20.
//