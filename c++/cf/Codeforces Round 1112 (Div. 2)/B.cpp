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
    int n,k;
    cin>>n>>k;
    string s="";
    if (k%2==1)
    {
        int num_1 = k / 2 + 1;
        s.append(num_1, '1');
        s.append(num_1, '0');
        s.push_back('0');
        if (s.length()>n)
        {
            cout<<"-1"<<endl;
            return;
        }
        for (int i=s.size(); i<n; i++)
        {
            if (s.back()=='1')
                s.push_back('0');
            else
                s.push_back('1');
        }
    }
    else
    {
        int num_1=k/2 + 1;
        s.append(num_1, '1');
        s.append(num_1, '0');
        if (s.length()>n)
        {
            cout<<"-1"<<endl;
            return;
        }
        for (int i=s.size(); i<n; i++)
        {
            if (s.back()=='1')
                s.push_back('0');
            else
                s.push_back('1');
        }
    }
    cout<<s<<endl;
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
}//
// Created by Administrator on 2026/7/26.
//