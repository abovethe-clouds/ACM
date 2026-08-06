#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
vector<pii> mp[5005];
bool SPFA(int start,int n,vector<int> &dis)
{
    queue<int> q;
    int cnt[n+1]={},vis[n+1]={};
    fill(dis.begin(), dis.end(),inf);
    dis[start] = 0;
    q.push(start);
    while (!q.empty())
    {
        auto i = q.front();
        vis[i] = 0;//出队
        q.pop();
        for (auto ii : mp[i] )
        {
            if(dis[i]+ii.second<dis[ii.first])
            {
                cnt[ii.first]++;
                dis[ii.first] = dis[i] + ii.second;
                if (!vis[ii.first])
                {
                    q.push(ii.first);
                    vis[ii.first] = 1;
                }
            }
            if (cnt[ii.first] == n)
            {
                return 1;
            }
        }
    }
    return  0;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> num(n + 1, inf),cnt(n+1,0);
    for (int i = 0; i < m; i++)
    {
        int op;
        cin>>op;
        if (op==1)
        {
            int e1,e2,v;
            cin>>e1>>e2>>v;
            mp[e1].emplace_back(e2,-v);
        }
        if (op==2)
        {
            int e1,e2,v;
            cin>>e1>>e2>>v;
            mp[e2].emplace_back(e1,v);
        }
        if (op==3)
        {
            int e1,e2;
            cin>>e1>>e2;
            mp[e2].emplace_back(e1,0);
            mp[e1].emplace_back(e2,0);
        }
    }
    num[0]=0;
    for (int i=1;i<=n;i++)
        mp[0].emplace_back(i,0);
    vector<int> dis(n+3);
    if (SPFA(0,n+1,dis))
    {
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;

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
// Created by Administrator on 2026/7/29.
//
