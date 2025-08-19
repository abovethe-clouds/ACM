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

struct info
{
    int x, left, right;
};

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

int n;
vector<info> mp(100005);
int cnt = 0;


map<int, int> mp1,mp2;
void dfs(int root, int l, int r)
{
    if (mp[root].x > l && mp[root].x < r)
    {
        cnt++;
        mp1[mp[root].x]++;
        //cout << mp[root].x << endl;
    }
    if (mp[root].left != -1)
        dfs(mp[root].left, l,min(mp[root].x,r));
    if (mp[root].right != -1)
        dfs(mp[root].right, max(mp[root].x,l), r);
}

void solve()
{
    n = read();
    bool root[n + 1] = {};
    for (int i = 1; i <= n; i++)
    {
        mp[i].x = read();
        mp2[mp[i].x]++;
        mp[i].left = read();
        mp[i].right = read();
        if (mp[i].left != -1)
            root[mp[i].left] = true;
        if (mp[i].right != -1)
            root[mp[i].right] = true;
    }
    int true_root;
    for (int i = 1; i <= n; i++)
    {
        if (!root[i])
        {
            true_root = i;
            break;
        }
    }
    dfs(true_root, -inf, inf);
    int ans = 0;
    for (auto i: mp2)
    {
        if (mp1[i.first]>0)
            ans+=mp2[i.first];
    }
    cout << n-ans << endl;
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
} //
// Created by Administrator on 25-8-18.
//
