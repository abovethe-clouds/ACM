#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;


void solve()
{
    int n,m;
    cin>>n>>m;
    string s[n];
    int ans[n+1]={};
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    for (int i = 0; i < m; i++)
    {
        int x0=0,y1=0;
        vector<int> xv,yv;
        for (int j = 0; j < n; j++)
        {
            if(s[j][i]=='0')
            {
                x0++;
                xv.push_back(j+1);
            }
            else
            {
                yv.push_back(j+1);
                y1++;
            }
        }
        if (x0==0||y1==0)
        {
            for (int k=1;k<=n; k++)
                ans[k]++;
        }
        else if (x0>y1)
        {
            for (auto k:yv)
            {
                ans[k]++;
            }
        }
        else
        {
            for (auto k:xv)
            {
                ans[k]++;
            }
        }
    }
    int maxx=*max_element(ans, ans+n+1);
    for (int i = 1; i <= n; i++)
    {
        if (ans[i]==maxx)
            cout<<i<<" ";
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
