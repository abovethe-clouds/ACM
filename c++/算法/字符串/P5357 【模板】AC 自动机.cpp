#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int cnt=1;
int trie[maxn][26],fail[maxn];
void instert(string s)
{
    int cur=1;//根节点
    for (auto i : s)
    {
        int path=i-'a';
        if(trie[cur][path]==0)
        {
            trie[cur][path]=++cnt;
        }
        cur=trie[cur][path];//下一个节点
    }
    return;
}
void bfs()
{
    int cur=1;
    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if(trie[cur][i])
        {
            fail[trie[cur][i]]=1;
            q.push(trie[cur][i]);
        }
    }
    while (!q.empty())
    {
        int t=q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {

        }
    }
}
void solve()
{
    int n;
    cin>>n;
    vector<string> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
        instert(a[i]);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
