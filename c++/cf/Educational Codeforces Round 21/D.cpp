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
    const int n = read();
    vector<ll> a(n+1),sum(n+1);
    for(int i = 1; i <= n; i++)
    {
        a[i] = read();
        sum[i] = sum[i-1] + a[i];
    }
    if(sum[n] % 2 != 0)
    {
        cout<<"NO"<<endl;
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        auto it = lower_bound(sum.begin(), sum.end(), sum[n]/2+a[i]);
        if (*it -a[i] == sum[n]/2&&it-sum.begin()>=i)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    reverse(a.begin()+1, a.end());
    for(int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        auto it = lower_bound(sum.begin(), sum.end(), sum[n]/2+a[i]);
        if (*it -a[i] == sum[n]/2&&it-sum.begin()>=i)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
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
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 25-8-20.
//
