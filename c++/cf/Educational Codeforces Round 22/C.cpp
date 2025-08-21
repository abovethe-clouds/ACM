#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
constexpr int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;

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
struct info
{
    int Alice,Bob;
    info(){Alice=-1,Bob=-1;}
};
void solve()
{
    const int n=read(),x=read();
    vector<int> mp[n+1];
    info tree[n+1]={};
    for (int i=0;i<n-1;i++)
    {
        int a = read(), b = read();
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    queue<pii> q;
    q.push({1,0});
    while(!q.empty())
    {
        pii a = q.front();
        tree[a.first].Alice=a.second;
        q.pop();
        for(auto i:mp[a.first])
        {
            if (tree[i].Alice==-1)
            {
                q.push({i,a.second+1});
            }
        }
    }
    q.push({x,0});
    while(!q.empty())
    {
        pii a = q.front();
        tree[a.first].Bob=a.second;
        q.pop();
        for(auto i:mp[a.first])
        {
            if (tree[i].Bob==-1)
            {
                q.push({i,a.second+1});
            }
        }
    }
    int maxx=0;
    for(int i=1;i<=n;i++)
    {
        maxx=max(maxx,(tree[i].Alice>tree[i].Bob?tree[i].Alice:0));
    }
    cout<<maxx*2<<endl;

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
// Created by Administrator on 2025/8/21.
//