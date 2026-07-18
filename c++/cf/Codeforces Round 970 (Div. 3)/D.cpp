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
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=2e5+5;
struct sett
{
    int f[maxn];
    void start()
    {
        for (int i=0;i<maxn;i++)
        {
            f[i]=i;
        }
    }
    int find(int x)
    {
        if (f[x] == x)
            return x;
        return f[x] = find(f[x]);
    }
    void add(int x, int y)
    {
        f[find(f[x])] = find(f[y]);
        return;
    }
};
void solve()
{
    sett t;
    t.start();
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);
    vector<bool> v(n+1),vis(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin>>s;
    for (int i=1;i<=n;i++)
    {
        v[i]=(s[i-1]=='0'?0:1);
    }
    for (int i=1;i<=n;i++)
    {
        if (vis[i])
        {
            continue;
        }
        int j=i,cnt=0;
        while (!vis[j])
        {
            vis[j]=true;
            b[j]=i;
            cnt+=(v[j]==0?1:0);
            j=a[j];
            t.add(j,i);
        }
        b[i]=cnt;
    }
    for (int i=1;i<=n;i++)
    {
        cout<<b[t.find(i)]<<" ";
    }
    cout<<endl;
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
