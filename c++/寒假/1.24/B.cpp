#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
int a[20][100000];
void solve()
{
    memset(a,0x3f,sizeof(a));
    int m,n;
    cin>>m>>n;
    for (int i = 0; i < m; i++)
    {
        cin>>a[0][i];
    }
    for (int i = 1; i <= log2(m); i++)
    {
        for (int j = 0; j < m-(1<<i)+1; j++)
        {
            a[i][j]=min(a[i-1][j],a[i-1][j+(1<<i-1)]);
        }
    }
    while (n--)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        int len=r-l+1;
        int y=log2(len);
        if(n>=1)
            cout<<min(a[y][l],a[y][r-(1<<y)+1])<<" ";
        else
            cout<<min(a[y][l],a[y][r-(1<<y)+1]);
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