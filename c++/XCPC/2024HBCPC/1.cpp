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
    string s;
    cin >> s;
    bool ch[26] = {};
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]!='i')ch[s[i] - 'a'] = true;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (ch[i])
        {
            ans++;
        }
    }
    cout << ans;
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
// Created by Administrator on 2026/5/21.
//
