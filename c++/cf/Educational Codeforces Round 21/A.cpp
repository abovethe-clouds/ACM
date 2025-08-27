#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;


void solve()
{
    ll n;
    cin>>n;
    int len=to_string(n).length();
    ll a=1;
    for(int i=1;i<len;i++)
        a*=10;
    int h=n/a;
    int next=(h+1)*a;
    cout<<next-n<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 25-8-20.
//
