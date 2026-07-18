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
ll fast_pow(ll a, ll b, int p)
{
    a %= p;
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % p;
        }
        a = a * a % p;
        b /= 2;
    }
    return ans;
}
struct point
{
    char op;
    ll x, y;int where;
};

void solve()
{
    int n;
    cin >> n;
    vector<point> arr(n + 1);
    vector<ll> ans(n + 1, 0);
    vector<int> in(n + 1, 0);
    vector<vector<int>> mp(n + 1);;

    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'N')
        {
            arr[i].op = 'N';
            cin >> arr[i].x;
            arr[i].where = i;
            ans[arr[i].where] = arr[i].x;
        } else
        {
            arr[i].op = ch;
            cin >> arr[i].x>>arr[i].y;
            arr[i].where = i;
            in[i]+=2;
            mp[arr[i].x].push_back(i);
            mp[arr[i].y].push_back(i);
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto i: mp[x])
        {
            in[i]--;
            if (in[i] == 0)
            {
                q.push(i);
            }
        }
        if (arr[x].op=='N')
            continue;
        const ll a=ans[arr[x].x], b=ans[arr[x].y];
        if (arr[x].op=='+')
            ans[arr[x].where]=(a+b)%mod;
        else if (arr[x].op=='*')
            ans[arr[x].where]=(a*b)%mod;
        else
            ans[arr[x].where]=(a*fast_pow(2,b,mod))%mod;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
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
