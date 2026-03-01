#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef pair<int,int> pii;
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

vector<int> prime;
vector<bool> is_prime(1e6 + 5, true);

void prime_1e6()
{
    int maxn = 1e6 + 5;
    for (int i = 2; i < maxn; i++)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && i * prime[j] < maxn; j++)
        {
            is_prime[i * prime[j]] = false;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
}

vector<int> is_only_one_prime(1e6 + 5, 0);

void is_only_one_prime1()
{
    is_only_one_prime[1] = 1;
    for (int i = 2; i <= 1e6; i++)
    {
        if (is_prime[i])
        {
            is_only_one_prime[i] = i;
            continue;
        }
        for (int j = 0; j < prime.size() && prime[j] < i; j++)
        {
            if (i % prime[j] == 0)
            {
                int c = i;
                while (c % prime[j] == 0)
                {
                    c /= prime[j];
                }
                if (c == 1)
                {
                    is_only_one_prime[i] = prime[j];
                }
                break;
            }
        }
    }
}

void solve()
{
    int n = read();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = read();
    }
    if (is_sorted(a.begin(), a.end()))
    {
        cout << "Bob\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!is_only_one_prime[a[i]])
        {
            cout << "Alice\n";
            return;
        }
        else
        {
            a[i] = is_only_one_prime[a[i]];
        }
    }
    if (is_sorted(a.begin(), a.end()))
    {
        cout << "Bob\n";
        return;
    }
    cout << "Alice\n";
}

signed main()
{
    prime_1e6();
    is_only_one_prime1();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    t = read();
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 2026/2/28.
//
