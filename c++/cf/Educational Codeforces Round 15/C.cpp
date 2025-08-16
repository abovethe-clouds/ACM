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
int n,m;
vector<int> a,b;
bool judge(int x)
{
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(b.begin(), b.end(), a[i]);
        int dist = INT_MAX;

        if (it != b.end())
            dist = min(dist, abs(a[i] - *it));
        if (it != b.begin())
            dist = min(dist, abs(a[i] - *prev(it)));

        if (dist > x)
            return false;
    }
    return true;
}
void solve()
{
    n=read(),m=read();
    for(int i=0;i<n;i++)
        a.push_back(read());
    for(int i=0;i<m;i++)
        b.push_back(read());
    int l=0,r=2e9+5;
    while(l<r)
    {
        int mid=l+(r-l)/2;
        if (judge(mid))
            r = mid;
        else
            l = mid + 1;

    }
    cout<<l<<endl;
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
