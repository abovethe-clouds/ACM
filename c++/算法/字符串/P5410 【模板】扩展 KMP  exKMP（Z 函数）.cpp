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
int read()
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
vector<int> z(string s)
{
    int n=s.length();
    vector<int> z(n);
    z[0]=n;
    int c=1,r=1;
    for(int i=1;i<n;i++)
    {
        if (i<r)
            z[i]=min(r-i,z[i-c]);
        while (i+z[i]<n&&s[z[i]]==s[i+z[i]])
            z[i]++;
        if (z[i] + i >r)
        {
            r=i+z[i];
            c=i;
        }
    }
    return z;
}
vector<int> e(string s,string t)
{
    vector<int> zt=z(t);
    int n=s.length(),m=t.length();
    vector<int> ex(n);
    int c=0,r=0;
    for(int i=0;i<n;i++)
    {
        if (i<r)
        {
            ex[i]=min(zt[i-c],r-i);
        }
        while (i+ex[i]<n&&ex[i]<m&&s[i+ex[i]]==t[ex[i]])
            ex[i]++;
        if (i+ex[i]>r)
        {
            r=i+ex[i];
            c=i;
        }
    }
    return ex;
}
ll hanser(vector<int> x)
{
    ll ans=0;
    for (int i=0;i<x.size();i++)
        ans^=(i+1)*1ll*(x[i]+1);
    return ans;
}
void solve()
{
    string a,b;
    cin>>a>>b;
    cout<<hanser(z(b))<<endl;
    cout<<hanser(e(a,b))<<endl;
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
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
