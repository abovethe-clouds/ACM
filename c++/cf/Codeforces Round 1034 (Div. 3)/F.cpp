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
vector<int> prime;

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

void primes()
{
    int n = 1e5;
    bool is_prime[n + 1] = {};
    is_prime[0] = is_prime[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!is_prime[i])
        {
            prime.push_back(i);
        }
        for (auto p: prime)
        {
            if (i * p > n) break;
            is_prime[i * p] = true;
            if (i % p == 0) break;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    int m = upper_bound(prime.begin(), prime.end(), n) - prime.begin();
    vector<bool> used(n + 1, false);
    vector<vector<int> > a(m);
    for (int i = m-1; i >=0; i--)
    {
        for (int j = 1; j * prime[i] <= n; j++)
        {
            if (!used[j * prime[i]])
            {
                a[i].push_back(j * prime[i]);
                used[j * prime[i]] = true;
            }
        }
    }
    vector<int> ans(n+1);
    for (int i = 0; i < m; i++)
    {
        if (a[i].empty())
            continue;
        for (int j=0;j<a[i].size()-1;j++)
        {

            ans[a[i][j]]=a[i][j+1];
        }

        ans[a[i].back()]=a[i][0];
    }
    ans[1]=1;

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    primes();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
