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

void solve()
{
    const int n = read(),m = read();
    vector<int> mp(n);
    for (int i = 0; i < n; ++i)
        mp[i] = read();
    int ans = 0;
    int l=0,r=0;
    queue<int> q;
    int ansl=-1,ansr=-1,maxx=0,cnt=0;
    for (;r<n;r++)
    {
        if (mp[r]==0)
            q.push(r);
        if (q.size()>m)
        {
            l=q.front()+1;
            q.pop();
        }
        if (r-l+1>maxx)
        {
            maxx = r-l+1;
            ansl = l;
            ansr = r;
            cnt=q.size();
        }
    }
    cout<<maxx<<endl;
    for (int i=0;i<n;i++)
    {
        if (i>=ansl && i<=ansr)
        {
            cout<<1<<" ";
        }
        else
            cout<<mp[i]<<" ";
    }

}

int main()
{

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
