#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
const int dx[8] = {-1,0,1,0,-1,-1,1,1}, dy[8] = {0,1,0,-1,-1,1,-1,1};
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
int n, m;
int judge[101][11] = {};
vector<int> dp(1<<20,-1);
bool vis[1 << 20 + 1] = {};
void solve()
{
    n = read(), m = read();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            judge[i][j] = read();
        } 
    }
    queue<int> q;
    q.push((1 << n) - 1);
    dp[(1 << n) - 1] = 0;
    vis[(1 << n) - 1] = 1;
    while (!q.empty())
    {
        int top1 = q.front();
        q.pop();
        vis[top1] = 1;
        int p = dp[top1] + 1;
        for (int i = 0; i < m;i++)
        {
            int top = top1;
            for (int j = 0; j < n; j++)
            {
                switch (judge[i][j])
                {
                case 1:
                    top = top & ((1 << n) - 1 - (1 << j ));
                    break;
                
                case -1:
                    top = top | (1 << j );
                    break;
                }
            }
            if(top==0)
            {
                cout << p;
                return;
            }
            if(vis[top]==0)
            {
                q.push(top);
                dp[top] =  p;
                vis[top] = 1;
            }
        }
    }
    cout << -1;
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
    while(t--)
        solve();

    return 0;
}