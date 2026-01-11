#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=2e5+10;
int ed[maxn],tree[maxn][26],fail[maxn],cnt=0,times[maxn];
vector<int> mp[maxn];
void insert(int i,string s)//插入字符串
{
    int cnr=0;
    for(auto c:s)
    {
        int to=c-'a';
        if(!tree[cnr][to])
            tree[cnr][to]=++cnt;
        cnr=tree[cnr][to];
    }
    ed[i]=cnr;
}
void setFail()// 构建失败指针 建立直通表
{
    queue<int> q;
    for(int i=0;i<26;i++)
    {
        if(tree[0][i])
        {
            fail[tree[0][i]]=0;
            q.push(tree[0][i]);
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<26;i++)
        {
            if(tree[u][i])
            {
                fail[tree[u][i]]=tree[fail[u]][i];
                q.push(tree[u][i]);
            }
            else
                tree[u][i]=tree[fail[u]][i];
        }
    }

}

void query(string s)//查询字符串
{
    int cur=0;
    for (auto i : s)
    {
        cur=tree[cur][i-'a'];
        times[cur]++;
    }
}
void addEdge(int u,int v)
{
    mp[u].push_back(v);
}
void dfs(int u)
{
    for(auto v:mp[u])
    {
        dfs(v);
        times[u]+=times[v];
    }
}
void solve()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        insert(i,s);
    }
    setFail();
    string text;
    cin>>text;
    query(text);
    for (int i=1;i<=cnt;i++)
    {
        addEdge(fail[i],i);
    }
    dfs(0);
    for (int i=1;i<=n;i++)
    {
        cout<<times[ed[i]]<<endl;
    }
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
}//
// Created by Administrator on 2026/1/11.
//