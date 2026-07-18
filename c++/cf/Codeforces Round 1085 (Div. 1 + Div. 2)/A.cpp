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

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int i=1;i<s.length()-1;i++)
    {
        if (s[i-1]=='1'&&s[i+1]=='1')
            s[i]='1';
    }
    int num_1=0;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]=='1')
            num_1++;
    }
    for (int i=1;i<s.length()-1;i++)
    {
        if (s[i-1]=='1'&&s[i+1]=='1')
            s[i]='0';
    }
    int num_0=0;
    for (int i=0;i<s.length();i++)
    {
        if (s[i]=='1')
            num_0++;
    }
    cout<<num_0<<" "<<num_1<<endl;
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
    cin >> t;
    while (t--)
        solve();
    return 0;
}
