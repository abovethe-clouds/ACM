#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=1e4+5;
vector<int> tree[maxn];
int in[maxn];
int deep[maxn];
int dfs(int rt)
{
    deep[rt]=1;
    for (auto i:tree[rt])
    {
        dfs(i);
    }
    for (auto i:tree[rt])
        deep[rt]=max(deep[rt],deep[i]+1);
    return deep[rt];
}
vector<int> ans;
void dfs1(int rt)
{
    ans.push_back(rt);
    for (auto i:tree[rt])
    {
        if (deep[i]==deep[rt]-1)
        {
            dfs1(i);
            break;
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        int m;
        cin>>m;
        for (int j=0; j<m; j++)
        {
            int k;
            cin>>k;
            tree[i].push_back(k);
            in[k]++;
        }
    }
    for (int i=0; i<n; i++)
        sort(tree[i].begin(),tree[i].end());
    int beg=0;
    for (int i=0; i<n; i++)
    {
        if (in[i]==0)
        {
            beg=i;
            break;
        }
    }
    dfs(beg);
    dfs1(beg);
    cout<<ans.size()<<endl;
    for (const int i : ans)
    {
        cout<<i<<" ";
    }

}

signed main()
{

#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    while (t--)
        solve();
    return 0;
}
