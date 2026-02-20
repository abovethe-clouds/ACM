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

void solve()
{
    int n = read(), sum = 0, maxx = 0;
    map<int,int> mp;
    mp.clear();
    vector<int> v(n), ans;
    for (int i = 0; i < n; i++)
    {
        v[i] = read();
        sum += v[i];
        mp[v[i]]++;
        maxx = max(maxx, v[i]);
    }
    if (n==1)
    {
        cout << v[0] << endl;
        return;
    }
    for (int i = n / 2; i <= n; i++)
    {

        if (sum % i == 0)
        {
            int avg = sum / i;
            if (avg < maxx)
                break;

            bool flag = 1;
            for (auto j: mp)
            {
                int need = avg - j.fir;
                if (need<0)
                {
                    flag = 0;
                    break;
                }
                if (need == 0)
                    continue;
                if (need == j.fir)
                {
                    if (j.sec % 2 != 0)
                    {
                        flag = 0;
                        break;
                    }
                } else
                {
                    if (!mp.count(need)||mp[need] != j.sec)
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag)
            {
                ans.push_back(avg);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto i: ans)
        cout << i << " ";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //t = read();
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 2026/2/7.
//
