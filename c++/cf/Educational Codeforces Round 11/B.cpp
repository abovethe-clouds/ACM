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
    const int n=read(), m=read();
    int mp[n][4];
    for (int i = 0; i < n; ++i)
    {
        mp[i][0] = 2 * i;  //
        mp[i][1] = 2 * (n + i);
        mp[i][2] = 2 * (n + i) + 1;
        mp[i][3] = 2 * i + 1;
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        ans.push_back(mp[i][1]);
        ans.push_back(mp[i][0]);
        ans.push_back(mp[i][2]);
        ans.push_back(mp[i][3]);
    }
    ans.erase(remove_if(ans.begin(), ans.end(),[&m](int x){return x>=m;}),ans.end());
    for (auto i=ans.begin(); i!=ans.end(); i++)
        cout << *i +1 << " ";
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
}
