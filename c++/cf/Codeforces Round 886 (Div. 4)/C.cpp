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
    int where_x, where_y;
    string s[8];
    for (int i = 0; i < 8; i++)
    {
        cin>>s[i];
        for (int j = 0; j < 8; j++)
        {
            if (s[i][j]!='.')
                where_x=i, where_y=j;
        }
    }
    stack<char> st;
    for (int i = where_x; i >= 0; i--)
    {
        if (s[i][where_y]!='.')
            st.push(s[i][where_y]);
        else
            break;
    }
    while (!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
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
    cin>>t;
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2025/10/5.
//