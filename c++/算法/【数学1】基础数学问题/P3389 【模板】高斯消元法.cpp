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
bool equal(double a, double b)
{
    return fabs(a - b) <= 1e-7;
}
bool solve()
{
    int n;
    cin>>n;
    vector<vector<double>> mat(n+1, vector<double>(n+2));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n+1; j++)
            cin>>mat[i][j];
    for (int i = 1; i <= n; i++)
    {
        int x=i;
        for (int j=i+1; j<=n; j++)
        {
            if (abs(mat[j][i])>abs(mat[x][i]))
                x=j;
        }
        swap(mat[x],mat[i]);
        if (equal(mat[i][i],0))
            return false;
        double u=mat[i][i];
        for (int j=1;j<=n+1;j++)
            mat[i][j]/=u;
        for (int j=1;j<=n;j++)
        {
            if (i!=j)
            {
                double u=mat[j][i]/mat[i][i];
                for (int k=1;k<=n+1;k++)
                    mat[j][k]-=u*mat[i][k];
            }
        }
    }
    for (int i=1;i<=n;i++)
        cout<<fixed<<setprecision(2)<<mat[i][n+1]<<endl;
    return true;
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
        if(!solve())
        {
            cout<<"No Solution"<<endl;
        }
    return 0;
}//
// Created by Administrator on 2026/7/22.
//