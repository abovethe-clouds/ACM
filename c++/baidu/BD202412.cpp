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
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;

void solve()
{
    string s;
    cin >> s;
    int cnt_1 = count(s.begin(), s.end(), '(');
    int cnt_2 = count(s.begin(), s.end(), ')');

    if (cnt_1 == cnt_2)
    {
        cout << 0 << endl;
        return;
    }

    if (cnt_1 > cnt_2)
    {
        deque<pair<char, int>> q;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                q.push_back({'(', i});
            else
            {
                if (!q.empty() && q.back().first == '(')
                    q.pop_back();
                else
                    q.push_back({')', i});
            }
        }
        int sec = q.back().second;
        string s1 = s.substr(sec);
        cout << count(s1.begin(), s1.end(), '(') << endl;
    }
    else
    {
        deque<pair<char, int>> q;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ')')
                q.push_back({')', i});
            else
            {
                if (!q.empty() && q.back().first == ')')
                    q.pop_back();
                else
                    q.push_back({'(', i});
            }
        }
        int sec = q.back().second;
        string s1 = s.substr(0, sec + 1);
        cout << count(s1.begin(), s1.end(), ')') << endl;
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
        solve();
    return 0;
}
