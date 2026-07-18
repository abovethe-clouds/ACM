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
bool have_x(int n,int  x)
{
    string s = to_string(n);
    if (s.find(to_string(x)) != string::npos)
        return true;
    return false;
}
void solve()//dp
{
    int n;
    cin>>n;
    vector<int> a(n), b(n),a1(3,0),b1(3,0);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    for(int i=0;i<n;i++)
    {
        int a11=0,a2=0,a3=0,b11=0,b2=0,b3=0;
        if (have_x(a[i],0))
        {
            a11=max(a1[0],b1[0]+1);
        }
        if (have_x(a[i],2))
        {
            a2=max(a1[1],b1[1]+1);
        }
        if (have_x(a[i],4))
        {
            a3=max(a1[2],b1[2]+1);
        }
        if (have_x(b[i],0))
        {
            b11=max(b1[0],a1[0]+1);
        }
        if (have_x(b[i],2))
        {
            b2=max(b1[1],a1[1]+1);
        }
        if (have_x(b[i],4))
        {
            b3=max(b1[2],a1[2]+1);
        }
        a1[0]=max(a1[0],a11);
        a1[1]=max(a1[1],a2);
        a1[2]=max(a1[2],a3);
        b1[0]=max(b1[0],b11);
        b1[1]=max(b1[1],b2);
        b1[2]=max(b1[2],b3);
    }
    cout<<max(*max_element(a1.begin(),a1.end()),*max_element(b1.begin(),b1.end()))<<endl;
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
// Created by Administrator on 2026/4/30.
//