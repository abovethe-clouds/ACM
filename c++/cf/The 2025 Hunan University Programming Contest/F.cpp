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
    const int n=read();
    vector<int> a(n);
    for(int i=0;i<n;i++)
        a[i]=read();
    if (n==1)
    {
        cout<<"YES"<<endl;
        return;
    }
    if (!(a[0]%2==1 && a[n-1]%2==1))
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {
        for (int i=1;i<n-1;i++)
        {
            if (a[i]%2==1)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
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
    int t = read();

    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2025/8/29.
//