#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=1e5+7;

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
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}
bool judge[maxn]={};
void solve()
{
    int n = read(), m = read();
    queue<int> q;
    unordered_map<int, int> mp;
    for (int i = 1; i <= m; i++)
    {
        int a=read();
        if (!judge[a])
            q.push(a);
        judge[a]=1;
        mp[a]++;
    }
    vector<pair<int, int>> p(mp.begin(), mp.end());
    sort(p.begin(), p.end(), cmp);
    int ans = 0;
    int cnt=0;
    while (!q.empty())
    {
        int a = q.front();
        judge[a]=0;
        q.pop();
        int b=p[cnt++].first;
        if (a!=b)
            ans++;
    }
    cout<<ans<<endl;
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
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
