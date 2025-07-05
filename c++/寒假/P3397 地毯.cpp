#include <bits/stdc++.h>  
using namespace std;
int n,m,x11,y11,x2,y2;
int a[10001][10001],s[10001][10001];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x11>>y11>>x2>>y2;
        a[x11][y11]++;
        a[x2+1][y2+1]++;
        a[x11][y2+1]--;
        a[x2+1][y11]--;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            s[i][j]=s[i-1][j]+s[i][j-1]+a[i][j]-s[i-1][j-1];
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
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
}