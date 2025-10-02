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
    string s;
    cin>>s;
    int cnt0=0, cnt1=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
            cnt1++;
        if(s[i]=='0')
            cnt0++;
    }
    string s2=s;
    sort(s2.begin(), s2.end());
    if (s2==s)
    {
        cout<<1<<endl;
        return;
    }
    int ans=0;
    if (s[0]=='1')
        ans++;
    for(int i=1;i<cnt0;i++)
    {
        if(s[i]=='1'&&s[i-1]=='0')
            ans++;
    }
    if (s[cnt0]=='0')
        ans++;
    for(int i=cnt0+1;i<s.length();i++)
    {
        if(s[i]=='0'&&s[i-1]=='1')
            ans++;
    }
    cout<<ans<<endl;
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
    cin>>t;
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2025/10/2.
//