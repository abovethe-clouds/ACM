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
    int n;string s;
    cin>>n>>s;
    int l=sqrt(n);
    if (l*l==n)
    {
        int i=0,j=0,k=0;
        for (i=0;i<l;i++)
        {
            for (int j=0;j<l;j++)
            {
                if (i==0||i==l-1||j==0||j==l-1)
                {
                    if (s[k++]!='1')
                    {
                        cout<<"NO"<<endl;
                        return;
                    }
                }
                else
                {
                    if (s[k++]!='0')
                    {
                        cout<<"NO"<<endl;
                        return;
                    }
                }
            }
        }
    }
    else
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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
