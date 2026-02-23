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
void solve()
{
    int n=read(),m=read();
    vector<vector<int>> map(n+2,vector<int>(n+2,0));
    for (int i=0; i<m; i++)
    {
        int x1=read(),y1=read(),x2=read(),y2=read();
        map[x1][y1]++;
        map[x1][y2+1]--;
        map[x2+1][y1]--;
        map[x2+1][y2+1]++;
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            map[i][j]+=map[i-1][j]+map[i][j-1]-map[i-1][j-1];
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
// #ifndef ONLINE_JUDGE
//     freopen("test.in", "r", stdin);
//     freopen("test.out", "w", stdout);
// #endif
    int t = 1;
    while(t--)
        solve();

    return 0;
}