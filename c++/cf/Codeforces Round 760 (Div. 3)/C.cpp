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
    int n = read(),gcd_odd,gcd_even;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = read();
    vector<int> odd, even;
    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0)
        {
            even.push_back(a[i]);
        }
        else
            odd.push_back(a[i]);
    }
    gcd_even=even[0], gcd_odd=odd[0];
    for (int i = 1; i < even.size(); i++)
        gcd_even = gcd(gcd_even , even[i]);
    for (int i = 1; i < odd.size(); i++)
        gcd_odd = gcd(gcd_odd , odd[i]);
    bool flag = true;
    for (int i = 0; i < even.size(); i++)
    {
        if (even[i] % gcd_odd == 0)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout<<gcd_odd<<endl;
        return;
    }
    flag = true;
    for (int i = 0; i < odd.size(); i++)
    {
        if (odd[i] % gcd_even == 0)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout<<gcd_even<<endl;
        return;
    }
    cout<<0<<endl;
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
    t=read();
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2025/10/16.
//