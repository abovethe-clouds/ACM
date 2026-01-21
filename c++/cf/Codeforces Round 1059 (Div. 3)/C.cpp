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
int hig_1(int x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x - (x >> 1);
}
void solve()
{
    int a=read(),b=read();
    if (a==b)
    {
        cout<<0<<endl;
        return;
    }
    if (hig_1(b)>hig_1(a))
    {
        cout<<-1<<endl;
        return;
    }
    vector<int> ans;
    int hig=log2(hig_1(a))-1;
    for (int i=hig;i>=0;i--)
    {
        if ((a>>i&1)!=(b>>i&1))
        {
            int tmp=1<<i;
            ans.emplace_back(tmp);
            a^=tmp;
            if (a==b)
            {
                cout<<ans.size()<<endl;
                for (auto x:ans)
                    cout<<x<<" ";
                cout<<endl;
                return;
            }
        }
    }
    if (a!=b)
    {
        int tmp=hig_1(a);
        ans.emplace_back(tmp);
        a^=tmp;

    }
    if (a==b)
    {
        cout<<ans.size()<<endl;
        for (auto x:ans)
            cout<<x<<" ";
        cout<<endl;
    }
    else
    {
        cout<<-1<<endl;
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
    t = read();
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2026/1/21.
//