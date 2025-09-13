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
constexpr int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
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
    const int N = read();
    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++)
        v[i] = read();
    int even = -inf, odd = inf, num_odd = 0, num_even = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 0 && v[i] > odd)
            odd = v[i], num_odd = i;
        else if (i % 2 == 1 && v[i] < even)
            even = v[i], num_even = i;
    }
    swap(v[num_even], v[num_odd]);
    int ans=abs(num_even - num_odd);
    for (int i = 1; i <= N; i++)
    {
        if (i%2==0)
            ans-=v[i];
        else
            ans+=v[i];
    }
    cout << ans << endl;
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
    t = read();
    while (t--)
        solve();
    return 0;
}
