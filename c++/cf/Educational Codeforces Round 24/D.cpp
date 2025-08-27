#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, pair<int,int>> pii;
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
    int n = read(),a=read();
    vector<int> v(n),color(1e6+5);
    for (int i = 0; i < n; i++)
        v[i] = read();
    vector<bool> b(1e6+5, true);
    b[a]=false;
    for (int i = 0; i < n; i++)
    {

        if (color[v[i]] < color[a])
            b[v[i]] = false;
        color[v[i]]++;
    }
    for (int i = 1; i < 1e6+5; i++)
    {
        if (b[i]&&color[i]>=color[a])
        {
            cout << i << endl;
            return;
        }
    }
    cout<<-1<<endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2025/8/25.
//