#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"

#define int long long
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

struct casino
{
    int l, r, value;
};

void solve()
{
    const int n = read();
    int coin = read();
    vector<casino> cas(n);
    for (int i = 0; i < n; i++)
    {
        cas[i].l = read();
        cas[i].r = read();
        cas[i].value = read();
    }
    sort(cas.begin(), cas.end(),
         [](const casino &a, const casino &b)
         {
             if (a.value != b.value)
             {
                 return a.value < b.value;
             }
             if (a.l != b.l)
             {
                 return a.l < b.l;
             }
             if (a.r != b.r)
             {
                 return a.r < b.r;
             }

         });
    for (int i = 0; i < n; i++)
    {
        if (cas[i].l<=coin&&coin<=cas[i].r)
        {
            coin=max(coin,cas[i].value);
        }
    }
    cout << coin << endl;
    return;
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
    int t = read();
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 2025/9/2.
//
