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
    int n,m;
    cout<<"Yes"<<endl;
    cin>>n>>m;
    cout<<m<<" ";
    bool flag=true;
    string s;
    cin>>s;
    for (int i=0;i<n-1;i++)
    {
        char c=s[i];
        if (c=='&'&&flag)
            cout<<m<<" ";
        else
        {
            flag = false;
            cout<<0<<" ";
        }
    }
    cout<<endl;
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
}
