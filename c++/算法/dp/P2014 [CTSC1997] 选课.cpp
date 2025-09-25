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

int N, M;
vector<int> mp[301];
int value[301];
int dp[301][301][301];
int dfs(int root,int choose_pre,int choose_num)
{
    if (choose_num == 0)
        return 0;
    if (choose_num==1||choose_pre==0)
        return value[root];
    if (dp[root][choose_pre][choose_num]!=-1)
        return dp[root][choose_pre][choose_num];
    int ans=dfs(root,choose_pre-1,choose_num);
    int v=mp[root][choose_pre-1];
    for (int i=1;i<choose_num;i++)
    {
        ans=max(ans,dfs(root,choose_pre-1,choose_num-i)+dfs(v,mp[v].size(),i));
    }
    dp[root][choose_pre][choose_num] = ans;
    return ans;
}

void solve()
{
    N = read();
    M = read();
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; i++)
    {
        mp[read()].push_back(i);
        value[i] = read();
    }
    cout << dfs(0, mp[0].size(), M+1) << endl;
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
