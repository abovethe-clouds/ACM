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
bool is_one_num(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
        if (v[i] != v[i + 1]) return false;
    return true;
}
void solve()
{
    int n= read();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = read();
    if (n==1)
    {
        cout<<1<<endl;
        return;
    }
    bool flag = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i]<=a[i+1]) continue;
        else
        {
            flag=false;
            break;
        }
    }
    if (!flag)
    {
        cout<<1<<endl;
        return;
    }
    cout<<n<<endl;

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
// Created by Administrator on 2026/2/27.
//