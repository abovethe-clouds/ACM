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
vector<vector<int>> base(101,vector<int>(105,0));
vector<int> where(105,-1);
void ins(vector<int> &v,int id)
{
    for (int i=1;i<=100;i++)
    {
        if (v[i])
        {
            if (where[i]==-1)
            {
                base[i]=v;
                where[i]=id;
                return;
            }
            for (int j=1;j<=104;j++)
            {
                v[j]^=base[i][j];
            }
        }
    }
}
void start()
{
    for (auto &v:base)
        for (auto &i:v)
            i=0;
    for (auto &i:where)
        i=-1;
}
void solve()
{
    start();
    int k;
    cin>>k;
    for (int i=0;i<k;i++)
    {
        int c,s;
        cin>>c>>s;
        vector<int> v(105);
        v[104]=s;
        for (int j=0;j<c;j++)
        {
            int x;
            cin>>x;
            v[x]^=1;
        }
        ins(v, i);
    }
    int q;
    cin>>q;
    for (int i=0;i<q;i++)
    {
        int d;
        cin>>d;
        vector<int> v(105);
        for (int j=0;j<d;j++)
        {
            int x;
            cin>>x;
            v[x]^=1;
        }
        bool flag=true;
        for (int o=0;o<=100;o++)
        {
            if (v[o]&&where[o]!=-1)
            {
                for (int j=1;j<=104;j++)
                {
                    v[j]^=base[o][j];
                }
            }
            else
            {
                if (v[o])
                {
                    cout<<-1<<endl;
                    flag=false;
                    break;
                }
            }
        }
        if (flag) cout<<v[104]<<endl;
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
    cin>>t;
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2026/8/4.
//