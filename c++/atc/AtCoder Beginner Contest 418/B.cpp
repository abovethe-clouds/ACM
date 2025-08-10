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
    string s;
    cin>>s;
    vector<int> where_t;
    int sum[s.length()+1]={};
    for(int i=0;i<s.length();i++)
    {
        if (s[i]=='t')
        {
            where_t.push_back(i+1);
            sum[i+1]=sum[i]+1;
        }
        else
            sum[i+1]=sum[i];
    }
    double ans=0;
    for(int i=0;i<where_t.size();i++)
    {
        for (int j=0;j<i;j++)
            if (where_t[i]-where_t[j]>=2)
            {
                double x=(sum[where_t[i]]-sum[where_t[j]-1]-2)*1.0/(where_t[i]-where_t[j]-1);
                ans=max(ans,x);
            }

    }
    printf("%.17lf\n",ans);
}

int main()
{

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
