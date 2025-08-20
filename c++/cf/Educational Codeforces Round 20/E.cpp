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

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    if (k == 0)
    {
        cout << "NO" << endl;
        return;
    }
    map<pii, bool> dp;
    map<pii, char> pre;
    dp[{0, 0}] = true;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'W')
        {
            for (int j = -k + 1; j < k; j++)
            {
                if (dp[{i - 1, j}])
                {
                    int new_j = j + 1;
                    if (abs(new_j) < k)
                    {
                        dp[{i, new_j}] = true;
                        pre[{i, new_j}] = 'W';
                    }
                }
            }
        }
        else if (s[i] == 'D')
        {
            for (int j = -k + 1; j < k; j++)
            {
                if (dp[{i - 1, j}])
                {
                    int new_j = j;
                    if (abs(new_j) < k)
                    {
                        dp[{i, new_j}] = true;
                        pre[{i, new_j}] = 'D';
                    }
                }
            }
        }
        else if (s[i] == 'L')
        {
            for (int j = -k + 1; j < k; j++)
            {
                if (dp[{i - 1, j}])
                {
                    int new_j = j - 1;
                    if (abs(new_j) < k)
                    {
                        dp[{i, new_j}] = true;
                        pre[{i, new_j}] = 'L';
                    }
                }
            }
        }
        else
        {
            for (int j = -k + 1; j < k; j++)
            {
                if (dp[{i - 1, j}])
                {
                    int new_j = j - 1;
                    if (abs(new_j) < k)
                    {
                        dp[{i, new_j}] = true;
                        pre[{i, new_j}] = 'L';
                    }
                    new_j = j;
                    if (abs(new_j) < k)
                    {
                        dp[{i, new_j}] = true;
                        pre[{i, new_j}] = 'D';
                    }
                    new_j = j + 1;
                    if (abs(new_j) < k)
                    {
                        dp[{i, new_j}] = true;
                        pre[{i, new_j}] = 'W';
                    }
                }
            }
        }
    }
    if (s[n] == 'W')
    {
        for (int j = -k + 1; j < k; j++)
        {
            if (dp[{n - 1, j}])
            {
                int new_j = j + 1;
                if (new_j == k || new_j == -k)
                {
                    dp[{n, new_j}] = true;
                    pre[{n, new_j}] = 'W';
                }
            }
        }
    }
    else if (s[n] == 'L')
    {
        for (int j = -k + 1; j < k; j++)
        {
            if (dp[{n - 1, j}])
            {
                int new_j = j - 1;
                if (new_j == k || new_j == -k)
                {
                    dp[{n, new_j}] = true;
                    pre[{n, new_j}] = 'L';
                }
            }
        }
    }
    else
    {
        for (int j = -k + 1; j < k; j++)
        {
            if (dp[{n - 1, j}])
            {
                int new_j = j + 1;
                if (new_j == k || new_j == -k)
                {
                    dp[{n, new_j}] = true;
                    pre[{n, new_j}] = 'W';
                }
                new_j = j - 1;
                if (new_j == k || new_j == -k)
                {
                    dp[{n, new_j}] = true;
                    pre[{n, new_j}] = 'L';
                }
            }
        }
    }
    if (!dp[{n, k}] && !dp[{n, -k}])
    {
        cout << "NO" << endl;
        return;
    }
    stack<char> st;
    pii no;
    if (dp[{n, k}])
    {
        no = {n, k};
    } else
    {
        no = {n, -k};
    }
    while (no.first != 0)
    {
        st.push(pre[no]);
        if (st.top() == 'W')
        {
            no = {no.first - 1, no.second - 1};
        } else if (st.top() == 'D')
        {
            no = {no.first - 1, no.second};
        } else
        {
            no = {no.first - 1, no.second + 1};
        }
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
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
} //
// Created by Administrator on 25-8-20.
//
