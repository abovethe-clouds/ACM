#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
typedef long long ll;
#define int long long
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=1e5+10;
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
vector<int> mp[maxn],v(maxn);
vector<bool> vis(maxn);
map<int,pii> list_pos;// first是链表下标，second是在链表中的下标
void dfs(int x)
{
    if (vis[x])
        return;
    vis[x]=true;
    mp[x].push_back(x);
    int begin=x;
    list_pos[begin]={begin,0};
    int next=v[x];
    while (next!=x)
    {
        if (next==begin)
        {
            break;
        }
        mp[begin].push_back(next);
        list_pos[next]={begin,static_cast<long long>(mp[begin].size())-1};
        next=v[next];
    }
}
int fast_pow(int a,int b,int p)
{
    int ans=1;
    while (b)
    {
        if (b&1)
        {
            ans=ans*a%p;
        }
        a=a*a%p;
        b/=2;
    }
    return ans;
}

void solve()
{
    int n=read();
    for (int i = 1; i <= n; i++)
        v[i]=read();
    for (int i=1;i<=n;i++)
    {
        dfs(i);
    }
    for (int i=1;i<=n;i++)
    {
        int list_where=list_pos[i].fir;
        int list_size=mp[list_where].size();
        if (list_size==1)
        {
            cout<<i<<" ";
            cout<<std::flush;
        }
        else
        {
            if (v[mp[list_where].back()]==list_where)//头尾相连
            {
                cout<<mp[list_where][(list_pos[i].second+fast_pow(10,100,mp[list_where].size()))%mp[list_where].size()]<<" ";
                cout<<std::flush;
            }
            else
            {
                cout<<mp[list_where].back()<<" ";
                cout<<std::flush;
            }
        }
    }

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
