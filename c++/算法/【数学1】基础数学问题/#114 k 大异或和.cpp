#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;

void gauss(vector<int> &arr,int &flag,int &len,int n)
{
    len = 1;
    for (int i = 63; i >= 0; i--)
    {
        for (int j = len; j <= n; j++)
        {
            if (arr[j] & (1LL << i))
            {
                swap(arr[len], arr[j]);
                break;
            }
        }
        if (arr[len] & (1LL << i))
        {
            for (int j = 1; j <= n; j++)
            {
                if (j != len && arr[j] & (1LL << i))
                    arr[j] ^= arr[len];
            }
            len++;
        }
    }
    len--;
    flag = (len != n);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(1e5+5);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int flag, len;
    gauss(arr, flag, len, n);
    int m;
    cin >> m;
    for (int o = 1; o <= m; o++)
    {
        int k;
        cin >> k;
        if (k == 1 && flag)
        {
            cout << 0 << endl;
            continue;
        }
        if (flag) k--;
        if (k >= (1LL << len))
        {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        for (int i = len, j = 0; i >= 1; i--, j++)
        {
            if (k & (1LL << j))
                ans ^= arr[i];
        }
        cout << ans << endl;
    }
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
    //cin >> t;
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 2026/7/24.
//
