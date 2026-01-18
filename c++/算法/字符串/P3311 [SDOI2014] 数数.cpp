#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 2e3 + 10;
int tree[maxn][10], fail[maxn], cnt = 0, times[maxn];
bool alert[maxn];
vector<int> mp[maxn];

void insert(int i, string s) //插入字符串
{
    int cnr = 0;
    for (auto c: s)
    {
        int to = c - '0';
        if (!tree[cnr][to])
            tree[cnr][to] = ++cnt;
        cnr = tree[cnr][to];
    }
    alert[cnr] = true;
}

void setFail() // 构建失败指针 建立直通表
{
    queue<int> q;
    for (int i = 0; i <= 9; i++)
    {
        if (tree[0][i])
        {
            fail[tree[0][i]] = 0;
            q.push(tree[0][i]);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 10; i++)
        {
            if (tree[u][i])
            {
                fail[tree[u][i]] = tree[fail[u]][i];
                q.push(tree[u][i]);
            } else
                tree[u][i] = tree[fail[u]][i];
        }
        alert[u] |= alert[fail[u]];
    }
}

int dp[maxn][maxn][2][2];
int n;
string num;

int f(const int i, const int j, const bool free, const bool has) //到第i个数字 树上第j个节点
{
    if (alert[j])
        return 0;
    if (i == num.length())
        return has;
    if (dp[i][j][free][has] != -1)
        return dp[i][j][free][has];
    int ans = 0;
    if (has == false)
    {
        if (free)
        {
            ans += f(i + 1, 0, true, false);
            ans%=mod;
            for (int to=1;to<=9;to++)
            {
                ans+=f(i+1,tree[j][to],true,true);
                ans%=mod;
            }
        }
        else
        {
            ans += f(i + 1, 0, true, false);
            ans%=mod;
            int top=num[i]-'0';
            for (int to=1;to<top;to++)
            {
                ans+=f(i+1,tree[j][to],true,true);
                ans%=mod;
            }
            ans+=f(i+1,tree[j][top],false,true);
            ans%=mod;
        }
    }
    else
    {
        if (free)
        {
            for (int to=0;to<=9;to++)
            {
                ans+=f(i+1,tree[j][to],true,true);
                ans%=mod;
            }
        }
        else
        {
            int top=num[i]-'0';
            for (int to=0;to<top;to++)
            {
                ans+=f(i+1,tree[j][to],true,true);
                ans%=mod;
            }
            ans+=f(i+1,tree[j][top],false,true);
            ans%=mod;
        }
    }
    ans%=mod;
    dp[i][j][free][has] = ans;
    return ans;
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> num;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        insert(i, s);
    }
    setFail();
    cout<<f(0,0,false,false)<<endl;
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
    //cin >> t;
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 2026/1/11.
//
