#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
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
    int n = read(), k = read();
    bool used[n + 1] = {};
    int permutation[n + 1] = {};
    int a[k];
    for (int i = 0; i < k; i++)
        a[i] = read();
    for (int i = 1; i < k; i++)
    {
        int pre = a[i - 1], next = a[i], sub;
        if (pre < next)
        {
            sub = next - pre;
        } else
        {
            sub = next + (n - pre);
        }
        if ((used[sub] == 1 && permutation[pre] == sub) ^ (used[sub] == 0 && permutation[pre] == 0))
        {
            permutation[pre] = sub;
            used[sub] = 1;
        } else
        {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> unUes;
    for (int i = 1; i <= n; i++)
    {
        if (used[i] == 0)
            unUes.push_back(i);
    }
    auto it = unUes.begin();
    for (int i = 1; i <= n; i++)
    {
        if (permutation[i] == 0)
            cout << *it++ << endl;
        else
            cout << permutation[i] << " ";
    }
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
} //
// Created by Administrator on 2025/8/25.
//
