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
    string s;
    int n;
    cin >> n;
    cin >> s;
    int num_1 = 0, num_0 = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            num_1++;
        else
            num_0++;
    }
    int num_end_1 = 0;
    for (int i = 1; i <= num_1; i++)
    {
        if (s[s.length() - i] == '1')
            num_end_1++;
    }
    cout << num_1 - num_end_1 << endl;
    return;
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
    //t=read();
    cin >> t;
    while (t--)
        solve();
    return 0;
}
