#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef pair<int,int> pii;
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
    int n;
    cin >> n;
    vector<int> v(n),ans(3e5+5,0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), [](int a, int b)
         { return a > b; });
    for (auto i:v)
    {
        ans[i]++;
    }
    for (int i=v[0]-1;i>=1;i--)
    {
        ans[i]+=ans[i+1];
    }
    for (int i=1;i<=3e5;i++)
    {
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    for (int i=3e5;i>=1;i--)
    {
        if (ans[i]!=0)
        {
            for (int j=i;j>=1;j--)
                cout<<ans[j];
            cout<<endl;
            return;
        }
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
    //t = read();
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2026/2/7.
//