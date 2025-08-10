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
    const int n = read(), k = read();
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        x %= k;
        mp[x]++;
        mp[k - x]++;
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        x %= k;
        if (mp[x] > 0 || mp[k - x] > 0)
        {
            if (mp[x] > 0)mp[x]--;
            if (mp[k - x] > 0)mp[k - x]--;
            continue;
        }
        flag = 0;
    }
    if (flag)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
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
    int t = read();
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
