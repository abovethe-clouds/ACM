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
    const int N = read();
    vector<pii> v(N);
    for (int i = 0; i < N; i++)
        v[i].first = read(), v[i].second = i;
    sort(v.begin(), v.end(),[](pii a,pii b){return a.fir>b.fir;});
    int l=v[0].second,r=v[0].second;
    for (int i=0;i<N;i++)
    {
        if (v[i].second<l-1||v[i].second>r+1)
        {
            cout<<"NO"<<endl;
            return;
        }
        if (v[i].second<l)
        {
            l=v[i].second;
        }
        if (v[i].second>r)
        {
            r=v[i].second;
        }
    }
    cout<<"YES"<<endl;
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
    t=read();
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2025/9/18.
//