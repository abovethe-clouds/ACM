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

void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v(n);
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        v[i].resize(m);
        for(int j=0;j<m;j++)
            cin>>v[i][j];
        reverse(v[i].begin(),v[i].end());
        vector<int> temp;
        unordered_map<int,bool> mp;
        for(int j=0;j<m;j++)
        {
            if (!mp[v[i][j]])
            {
                temp.push_back(v[i][j]);
                mp[v[i][j]]=true;
            }
        }
        //reverse(temp.begin(),temp.end());
        v[i]=temp;
    }
    vector<bool> judge(n,0);
    vector<int> ans;
    unordered_set<int> vis;

    for(int i=0;i<n;i++)
    {
        int id=-1;
        for (int j=0;j<n;j++)
        {
            if (!judge[j])
            {
                if (id==-1||v[j]<v[id])
                    id=j;
            }
        }
        for (auto k : v[id])
        {
            if (!vis.count(k))
            {
                ans.push_back(k);
                vis.insert(k);
            }
        }
        judge[id]=true;
        for (int j=0;j<n;j++)
        {
            if (judge[j]) continue;

            vector<int> temp;

            for (auto x : v[j])
            {
                if (!vis.count(x))
                    temp.push_back(x);
            }
            v[j]=temp;
        }
    }
    for (auto x : ans)
        cout << x << " ";
    cout<<endl;
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
    cin>>t;
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2026/3/14.
//