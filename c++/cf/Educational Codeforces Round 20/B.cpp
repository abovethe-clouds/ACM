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
    const int N = read();
    vector<int> v(N),zero;
    for (int i = 0; i < N; i++)
    {
        v[i] = read();
        if (v[i] == 0)
            zero.push_back(i);
    }
    for (int i = 0; i < N; i++)
    {
        if (v[i] == 0)
        {
            cout<<0<<" ";
            continue;
        }
        auto it=lower_bound(zero.begin(),zero.end(),i);
        if (it == zero.end())
        {
            --it;
            cout<<i-*it<<" ";
            continue;
        }
        if (it == zero.begin())
        {
            cout<<*it-i<<" ";
            continue;
        }
        int ans1=*it-i;
        --it;
        int ans2=i-*it;
        cout<<min(ans1,ans2)<<" ";

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
}//
// Created by Administrator on 25-8-19.
//
