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
int reverse_int_2(int x)
{
    string s="";
    while (x!=0)
    {
        s.push_back(x%2+'0');
        x/=2;
    }
    int baes=1,ans=0;
    for (int i=s.size()-1; i>=0; i--)
    {
        ans+=(s[i]-'0')*baes;
        baes*=2;
    }
    return ans;

}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }

    for (int i=0;i<n;i++)
    {
        v[i]=max(reverse_int_2(v[i])-v[i],0ll);
    }
    vector<int> u;
    int p=0;
    for (int i=0;i<n;i++)
    {
        if (v[i]==0)
        {
            u.push_back(p);
            p=0;
        }
        else
            p+=v[i];
    }
    u.push_back(p);
    sort(u.begin(),u.end(),greater<int>());
    for (int i=0;i<(u.size(),m);i++)
    {
        sum+=u[i];
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
// Created by Administrator on 2026/5/1.
//