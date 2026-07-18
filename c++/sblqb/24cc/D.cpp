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
int ooo[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), [](int a,int b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);
        int sum_a = 0, sum_b = 0;
        for (auto i : s1)
        {
            sum_a += ooo[i - '0'];
        }
        for (auto i : s2)
        {
            sum_b += ooo[i - '0'];
        }
        if (sum_a == sum_b)
        {
            return a < b;
        }
        else
            return sum_a < sum_b;
    });
    for (auto i : v)
        cout<<i<<" ";
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
// Created by Administrator on 2026/5/2.
//
