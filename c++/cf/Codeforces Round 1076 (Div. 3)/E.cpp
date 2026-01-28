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
#define print(x) cout<<x<<endl
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
    int n = read();
    vector<int> a(n),cnt(n+1,inf);
    for (int i = 0; i < n; i++)
    {
        a[i] = read();
        cnt[a[i]] = 1;
    }
    sort(a.begin(),a.end(),greater<int>());
    a.erase(unique(a.begin(),a.end()),a.end());
    for (auto v:a)
    {
        int i=v;
        if (i==1)
            continue;
        int c=1;
        while (i<=n)
        {
            for (int j=1;j<=n/i;j++)
            {
                if (cnt[j]==inf)
                    continue;
                cnt[i*j]=min(cnt[i*j],cnt[j]+c);
            }
            i*=v;
            c++;
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (cnt[i]==inf)
            cout<<-1<<" ";
        else
            cout<<cnt[i]<<" ";
    }
    cout<<endl;

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
    t = read();
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2026/1/25.
//