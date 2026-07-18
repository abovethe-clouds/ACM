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
int max_len(string s1,string s2)
{
    int maxx=0;
    for (int i=0;i<s1.size();i++)
    {
        int len=0;
        for (int j=0;j<s2.size();j++)
        {
            if (s1[i]==s2[j])
                len++;
            else
                break;
        }
        maxx=max(maxx,len);
    }
    return maxx;
}
void solve()
{
    string s;
    cin>>s;
    string s1=s;
    reverse(s.begin(), s.end());
    cout<<max_len(s,s1)<<endl;
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