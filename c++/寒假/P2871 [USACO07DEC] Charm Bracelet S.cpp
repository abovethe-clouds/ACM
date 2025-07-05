#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
int bao[3][12881],jiazhi[3403],rongliang[3403],n,m;
void solve()
{
    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        cin>>rongliang[i]>>jiazhi[i];
    }
    for(int i=1;i<=n;i++)
        for (int j = 0; j <= m; j++)
        {
            if(rongliang[i]<=j)
                bao[i%2][j]=max(bao[(i-1)%2][j],bao[(i-1)%2][j-rongliang[i]]+jiazhi[i]);
            else
                bao[(i)%2][j]=bao[(i-1)%2][j];
        }
    cout<<bao[n%2][m];    
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
};
/*
for(int i=1;i<=n;i++) 
    for (int j = m; j >= 1; j--)
        f[j]=max(f[j],f[j-w[i]]+v[i]);
01背包*/
/*
for(int i=1;i<=n;i++) 
    for (int j = 1; j <= m; j++)
       f[j]=max(f[j],f[j-w[i]]+v[i])
完全背包*/