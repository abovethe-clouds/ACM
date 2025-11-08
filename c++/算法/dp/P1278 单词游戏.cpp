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
}int n;
vector<string> words(16);
int ans[1<<16][26]={};
int dfs(int set,int end)
{
    if (ans[set][end]!=-1)
        return ans[set][end];
    unsigned long long maxx=0;
    for (int i = 0; i < n; i++)
    {
        if (((set>>i)&1)==1&&words[i].back()-'A'==end)
        {
            maxx=max(maxx,dfs(set ^ (1 << i), words[i][0] - 'A')+words[i].length());
        }
    }
    return ans[set][end]=maxx;
}
void solve()
{
    int c[5]={0,4,8,14,20};
    cin >> n;
    memset(ans, -1, sizeof(ans));
    int maxx=0;
    for (int i = 0; i < n; i++)
        cin>>words[i];
    for (int i = 0; i < n; i++)
    {
        ans[1<<i][words[i].back()-'A']=words[i].length();
    }
    for (int i=1;i<(1<<n);i++)
    {
        for (auto j : c)
        maxx=max(maxx,dfs(i,j));
    }
    cout<<maxx<<endl;
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
    //t=read();
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2025/11/1.
//