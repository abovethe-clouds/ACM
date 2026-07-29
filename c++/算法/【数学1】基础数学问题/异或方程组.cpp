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
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> mat(n+1, vector<int>(n+2));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n+1; j++)
            cin>>mat[i][j];
    for (int i = 1; i <= n; i++)
    {
        int x=i;
        for (int j=1;j<=n;j++)
        {
            if (j<i&&mat[j][j]==1)
                continue;
            if (mat[j][i]==1)
            {
                x=j;
                break;
            }
        }
        swap(mat[x],mat[i]);
        int u=mat[i][i];
        if (u==1)
        {
            for (int j=1;j<=n;j++)
            {
                if (i!=j&&mat[j][i]==1)
                {
                    for (int k=1;k<=n+1;k++)
                        mat[j][k]^=mat[i][k];
                }
            }
        }

    }
    int sign=1;
    for (int i=1;i<=n;i++)
    {
        if (mat[i][i]==0&&mat[i][n+1]!=0)
        {
            cout<<-1<<endl;
            return;
        }
        if (mat[i][i]==0)
        {
            sign=0;
        }
    }
    if (sign==0)
    {
        cout<<0<<endl;
        return;
    }
    for (int i=1;i<=n;i++)
        cout<<"x"<<i<<"="<<mat[i][n+1]<<endl;
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
// Created by Administrator on 2026/7/22.
//