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

string del_front_0(string s)
{
    if (s == "")
        return s;
    int i = 0;
    while (i < s.size() && s[i] == '0')
        i++;
    return s.substr(i);
}

string del_end_0(string s)
{
    if (s == "")
        return s;
    int i = s.length() - 1;
    while (i >= 0 && s[i] == '0')
        i--;
    return s.substr(0,i+1);
}

void solve()
{
    string s;
    cin >> s;
    bool point = false, first = false;
    int w = 0;
    auto pos = s.find('.');
    string a,b;
    if (pos == string::npos)
    {
        a = s;
        b = "";
    } else {
        a = string(s.begin(), s.begin() + pos);
        b = string(s.begin() + pos + 1, s.end());
    }
    a = del_front_0(a);
    b = del_end_0(b);
    int len=-1;
    if (a.size()>0)
    {
        len = a.size()-1;
    }
    else
    {
        for (auto x: b)
        {
            if (x=='0')
                len--;
            else
                break;
        }
    }
    deque<char> q;
    for (auto x: a)
    {
        q.push_back(x);
        if (point == false)
        {
            q.push_back('.');
            point = true;
        }
    }
    if (point)
    {
        for (auto x: b)
        {
            q.push_back(x);
        }
    }
    else
    {
        b=del_front_0(b);
        for (auto x: b)
        {
            q.push_back(x);
            if (point == false)
            {
                q.push_back('.');
                point = true;
            }
        }
    }
    if (q.back()=='.')
        q.pop_back();
    while (q.back()=='0')
        q.pop_back();
    if (q.back()=='.')
        q.pop_back();
    while (q.back()=='0')
        q.pop_back();
    while (q.empty() == false)
    {
        cout << q.front();
        q.pop_front();
    }
    if (len!=0)
    {
        cout<<"E"<<len<<endl;
    }
    return;
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
