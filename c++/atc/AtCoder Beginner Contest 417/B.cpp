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
    int n , m ;
    cin >> n >> m;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        mp[a]++;
    }
    for(int i=0;i<m;i++)
    {
        int a;
        cin >> a;
        if(mp[a]>0)
            mp[a]--;
    }
    for (auto i : mp)
    {
        for (int j=0;j<i.second;j++)
            cout<<i.fir<<" ";

    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //     freopen("test.in", "r", stdin);
    //     freopen("test.out", "w", stdout);
    // #endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
