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

bool solve()
{
    vector<int> v;
    string s;
    cin>>s;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] != 'l' && s[i] != 'q' && s[i] != 'b') v.push_back(i);
    }
    if (v.size() == 0) return true;
    int left = v[0], right = v[v.size() - 1], l = v[0], r = v[v.size() - 1];
    while (left <= right && s[left] == s[right])
    {
        left++;
        right--;
    }
    while (l >= 0 && r < len && s[l] == s[r])
    {
        l--;
        r++;
    }
    return left > right && l < 0;
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
        if (solve()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    return 0;
}

//
// Created by Administrator on 2026/5/2.
//
