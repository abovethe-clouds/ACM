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

pii div2(int x)
{
    int a, b;
    if (x & 1)
        b = x / 2, a = x - b;
    else
    {
        a = b = x / 2;
        a++;
        b--;
    }
    return {a, b};
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int sumx = 0, sumy = 0, sum = 0, cntx = 0, cnty = 0;
    for (char c: s)
    {
        int p;
        cin >> p;
        sum += p;
        pii ans = div2(p);
        if (c == '0')
        {
            sumx += ans.fir;
            cntx++;
        } else
        {
            sumy += ans.fir;
            cnty++;
        }
    }
    if (sum > x + y)
    {
        cout << "NO" << endl;
        return;
    }
    if (cntx == n || cnty == n)
    {
        if (cntx == n)
        {
            if (x < y + n  || sumx > x)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        } else
        {
            if (y < x + n || sumy > y)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
        return;
    }
    if (sumx <= x && sumy <= y)
    {
        cout << "YES" << endl;
    } else
        cout << "NO" << endl;
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
} //
// Created by Administrator on 2026/1/20.
//
