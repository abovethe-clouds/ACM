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

void print(vector<int>& a)
{
    cout << a[0];
    for (int i = 1; i < a.size(); i++)
    {
        cout << "," << a[i];
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<pair<string,pair<string,int>>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].first>>a[i].second.first>>a[i].second.second;
    }
    map<string,int> mp;
    while (m--)
    {
        string s;
        int u;
        cin>>s>>u;
        mp[s]=u;
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
    {
        solve();
    }

    return 0;
}
