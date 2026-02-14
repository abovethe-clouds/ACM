#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ull
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 998244353, inf = 0x3f3f3f3f, P = 131;
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

void prime_1e7()
{
    int maxn = 1e7 + 5;
    vector<bool> is_prime(maxn, true);
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
int fast_pow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if (b&1)
            ans=ans*a%mod;
        a=a*a%mod;
        b/=2;
    }
    return ans;
}
int Mul_1(int x)
{
    return fast_pow(x,mod-2);
}
void solve()
{
    int n = read();
    int lcm = 1;
    map<int, pii> prime_cnt; //每个质数的最大出现次数和第二大出现次数
    map<int, vector<pii> > v_i_prime; //每个数的质因数分解
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = read();
        int num = v[i];
        for (auto pri: prime)
        {
            if (pri*pri>num)
            {
                break;
            }
            if (num % pri == 0)
            {
                int cnt = 0;
                while (num % pri == 0)
                {
                    num /= pri;
                    cnt++;
                }
                v_i_prime[v[i]].push_back({pri, cnt});
                if (cnt > prime_cnt[pri].fir)
                {
                    prime_cnt[pri].sec = prime_cnt[pri].fir;
                    prime_cnt[pri].fir = cnt;
                }
                else if (cnt > prime_cnt[pri].sec)
                {
                    prime_cnt[pri].sec = cnt;
                }
            }

        }
        if (num>1)
        {
            v_i_prime[v[i]].push_back({num, 1});
            if (1 > prime_cnt[num].fir)
            {
                prime_cnt[num].sec = prime_cnt[num].fir;
                prime_cnt[num].fir = 1;
            }
            else if (1 > prime_cnt[num].sec)
            {
                prime_cnt[num].sec = 1;
            }
        }
    }
    for (auto i : prime_cnt)
    {
        lcm=(lcm*fast_pow(i.fir,i.sec.fir))%mod;
    }
    for (auto i: v)
    {
        int ans=lcm;
        for (auto &[p,c]: v_i_prime[i])
        {
            if (prime_cnt[p].first != c)
            {
                continue;
            }
            else
            {
                ans=ans*Mul_1(fast_pow(p,prime_cnt[p].fir-prime_cnt[p].sec))%mod;
            }
        }
        cout<<ans%mod<<" ";
    }
    cout<<endl;
}

signed main()
{
    prime_1e7();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    t = read();
    while (t--)
        solve();
    return 0;
}
