#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int long long
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;

void solve()
{
    int n;
    cin>>n;
    priority_queue<pii, vector<pii>, greater<pii> > red,white;
    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if (c==1&&d==1)
        {
            if (a<b)
            {
                red.push(make_pair(a,i+1));
            }
            else
                white.push(make_pair(b,i+1));
        }
        else
        {
            if (c==1)
            {
                red.push(make_pair(a,i+1));
            }
            else
            {
                white.push(make_pair(b,i+1));
            }
        }
    }
    cout<<red.size()<<" ";
    while(!red.empty())
    {
        auto it=red.top();
        red.pop();
        cout<<it.second<<" ";
    }
    cout<<endl<<white.size()<<" ";
    while(!white.empty())
    {
        auto it=white.top();
        white.pop();
        cout<<it.second<<" ";
    }
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
    while (t--)
        solve();
    return 0;
}
