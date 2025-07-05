// #include<bits/stdc++.h>
#include<iostream>
#define int long long

using namespace std;

const int N = 5e5 + 10;
const int mod = 1e9 + 7;

int n, m;
int a[N], p[100];

void solve()
{
    cin >> n;
    int ans = 0ll;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        for(int j = 0; j <= 63; j ++)
        {
            if((a[i] >> j) & 1ll) ans = (ans + ((((1ll << j) % mod) * p[j]) % mod)) % mod;
            else ans = (ans + ((((1ll << j) % mod) * max(0ll, i - p[j] - 1)) % mod)) % mod, ++ p[j];
        }
    }
    cout << ans << "\n";
    return;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int _T = 1;
    // cin >> _T;
    while(_T --)
    {
        solve();
    }
    return 0;
}