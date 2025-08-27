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

void solve()
{
    string s, t;
    cin >> s >> t;
    int letter[27] = {}, letter2[27] = {};
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '?')
            letter[26]++;
        else
            letter[s[i] - 'a']++;
    }
    for (int i = 0; i < t.length(); i++)
    {
        letter2[t[i] - 'a']++;
    }
    int letter3[26] = {};
    int i = 0;
    while (letter[26] != 0)
    {
        if (letter[t[i] - 'a'] > 0)
        {
            letter[t[i] - 'a']--;
        } else
        {
            letter[26]--;
            letter3[t[i] - 'a']++;
        }
        i++;
        if (i == t.length())
            i = 0;
    }
    string ans = s;
    for (int j = 0; j < ans.length(); j++)
    {
        if (ans[j] == '?')
        {
            bool flag = false;
            for (int c = 0; c < 26; c++)
            {
                if (letter3[c] > 0)
                {
                    ans[j] = char('a' + c);
                    letter3[c]--;
                    flag = true;
                    break;
                }
            }
            if (!flag) ans[j] = 'a';
        }
    }
    cout << ans << endl;
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
// Created by Administrator on 2025/8/26.
//
