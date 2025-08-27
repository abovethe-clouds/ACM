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
char mp[10][10];
void solve()
{
    for (int i = 0; i < 10; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
            mp[i][j] = s[j];
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            int x = 0, y = 0;
            for (int k = j; k < j+5; k++)
            {
                if (mp[i][k] == 'X')
                    x++;
                else if (mp[i][k] == '.')
                    y++;
            }
            if (x==4&&y==1)
            {
                cout<<"YES";
                return;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            int x = 0, y = 0;
            for (int k = j; k < j+5; k++)
            {
                if (mp[k][i] == 'X')
                    x++;
                else if (mp[k][i] == '.')
                    y++;
            }
            if (x==4&&y==1)
            {
                cout<<"YES";
                return;
            }
        }
    }

    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            int x = 0, y = 0;
            for (int k = 0; k < 5; k++)
            {
                if (mp[i+k][j+k] == 'X')
                    x++;
                else if (mp[i+k][j+k] == '.')
                    y++;
            }
            if (x==4&&y==1)
            {
                cout<<"YES";
                return;
            }
        }
    }

    for (int i = 4; i < 10; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            int x = 0, y = 0;
            for (int k = 0; k < 5; k++)
            {
                if (mp[i-k][j+k] == 'X')
                    x++;
                else if (mp[i-k][j+k] == '.')
                    y++;
            }
            if (x==4&&y==1)
            {
                cout<<"YES";
                return;
            }
        }
    }
    cout<<"NO";
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
}//
// Created by Administrator on 2025/8/26.
//