#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int base = 499, inf = 0x3f3f3f3f, P = 131;
bool is_palindrome(const string &s)
{
    int l=0, r=s.size()-1;
    while (l<r)
    {
        if (s[l]!=s[r])
            return false;
        l++;
        r--;
    }
    return true;
}
bool is_non_decreasing(const string &s)
{
    for (int i=1;i<s.size();i++)
    {
        if (s[i]<s[i-1])
            return false;
    }
    return true;
}
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for (int bit=0;bit<(1<<n);bit++)
    {
        string sub="", rem="";
        for (int i=0;i<n;i++)
        {
            if (bit&(1<<i))
                sub+=s[i];
            else
                rem+=s[i];
        }
        if (is_palindrome(rem) && is_non_decreasing(sub))
        {
            cout<<__builtin_popcount(bit)<<endl;
            for (int i=0;i<n;i++)
            {
                if (bit&(1<<i))
                    cout<<i+1<<" ";
            }
            cout<<endl;
            return;
        }
    }
    cout<<-1<<endl;

}

signed main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2026/1/21.
//