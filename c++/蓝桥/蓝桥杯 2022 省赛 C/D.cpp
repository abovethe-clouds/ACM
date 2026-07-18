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
int fast_pow(int a, int b)
{
    if (a==0) return 0;
    if (b==0) return 1;
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void solve()
{
    int n;
    cin>>n;
    int A,B;
    cin>>A;
    vector<int> a(A),b;
    for(int i=0;i<A;i++)
        cin>>a[i];
    cin>>B;
    b.resize(B);
    for(int i=0;i<B;i++)
        cin>>b[i];
    while (a.size()>b.size())
        b.push_back(0);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int sum=0,fac=1;
    sum+=a[0]-b[0];
    for (int i=1;i<a.size();i++)
    {
        fac*=max(max(a[i-1],b[i-1])+1,2LL);
        sum+=(a[i]-b[i])*fac;
    }
    cout<<sum<<endl;
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
//
// Created by Administrator on 2026/4/7.
//