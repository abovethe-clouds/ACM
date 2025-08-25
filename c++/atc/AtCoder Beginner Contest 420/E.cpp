#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, maxn=2e5+5;
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
int fa[maxn]={};
vector<int> v(maxn,0);
bool color[maxn]={};//0 w 1 b
int N,Q;
int find(int x)
{
    if (fa[x]==x)
        return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y)
{
    int find_x=find(x);
    int find_y=find(y);
    if(find_x!=find_y)
    {
        v[find_y]+=v[find_x];
    }
    fa[find_x]=find_y;
}
string judge(int x)
{
    int x_find=find(x);
    if (v[x_find]==0)
        return "No";
    else
        return "Yes";
}
void change(int x)
{
    int x_find=find(x);
    if (color[x]==0)
    {
        color[x]=1;
        v[x_find]++;
    }
    else
    {
        color[x]=0;
        v[x_find]--;
    }
}
void solve()
{
    cin>>N>>Q;
    for (int i = 0; i <= N; i++)
    {
        fa[i]=i;
    }
    for (int i = 1; i <= Q; i++)
    {
        int op;
        cin>>op;
        if (op==1)
        {
            int u,v;
            cin>>u>>v;
            merge(u,v);
        }
        else if (op==2)
        {
            int x;
            cin>>x;
            change(x);
        }
        else if (op==3)
        {
            int x;
            cin>>x;
            cout<<judge(x)<<endl;
        }
    }
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
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2025/8/24.
//