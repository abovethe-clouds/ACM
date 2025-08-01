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
char mp[100][100];
int dp[20][20] = {}, N;

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

void print()
{
    for (int i = 0; i < N; i++)
    {
        for (int h = 0; h < N; h++)
        {
            cout << dp[i][h] << " ";
        }
        cout << endl;
    }
}

int maxx = 0,maxn;
vector<int> load[21];
bool vis[21] = {};
int a[21], ans[21], cnt[21];
bool check(int x)
{
    for (auto i: load[x])
    {
        if (vis[i] == 0)
            return false;
    }
    return true;
}

void dfs(int x, int step, int sum)
{
    if (check(x))
    {
        if (sum>maxx)
        {
            maxx = sum;
            maxn = step;
            for (int i = 0; i <= step; ++i)
            {
                ans[i]=cnt[i];
            }
        }
        return;
    }
    for (auto i: load[x])
    {
        if (vis[i]==0)
        {
            vis[i]=1;
            cnt[step+1]=i;
            dfs(i, step+1, sum+a[i]);
            vis[i]=0;
        }
    }
    return;
}



void solve()
{
    const int N = read();
    for (int i = 1; i <= N; i++)
        a[i] = read();

    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <=N; j++)
        {
            int qqq = read();
            if (qqq == 1)
                load[i].push_back(j);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        vis[i] = true;
        cnt[1] = i;
        dfs(i, 1, a[i]);
        vis[i] = false;
    }
    for (int i = 1; i <= maxn; i++)
        cout<<ans[i]<<" ";
    cout<<endl<<maxx;;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();

    return 0;
}
