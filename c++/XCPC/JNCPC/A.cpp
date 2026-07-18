#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;

string op(char op, string to, string mark1, string make2)
{
    cout << op << " " << to << " " << mark1 << " " << make2 << endl;
    fflush(stdout);
    string s;
    cin >> s;
    if (s == "err") exit(0);
    return s;
}

string better(string a, string b)
{
    cout << "? " << a << " " << b << endl;
    fflush(stdout);
    string s;
    cin >> s;
    if (s == "err") exit(0);
    return s;
}

int dfs(int n)
{

    string sa, sb, sc, sd;
    if (n & 1)
    {
        sa = "b";
        sb = "a";
        sc = "d";
        sd = "c";
    }
    else
    {
        sa = "a";
        sb = "b";
        sc = "c";
        sd = "d";
    }
    if (n>=740)
    {
        op('*',"r1",sa,sd);
        op('*',"r2",sb,sc);
        string ans=better("r1","r2");
        if (ans == "=") return 0;
        if (ans == ">") return 1;
        return -1;
    }
    op('/', "r1", sa, sb);
    op('/', "r2", sc, sd);
    string s = better("r1", "r2");
    if (s != "=")
    {
        if (s == ">") return 1;
        else return -1;
    }
    op('*', "r3", sb, "r1");
    op('-', sa, sa, "r3");
    op('*', "r3", sd, "r2");
    op('-', sc, sc, "r3");
    string s1 = better("r0", sa);
    string s2 = better("r0", sc);
    if (s1 == s2 && s2 == "=")
    {
        return 0;
    }
    if (s1 == "=")
    {
        return -1;
    }
    if (s2 == "=")
    {
        return 1;
    }

    return -dfs(n + 1);
}

void solve()
{
    int ans = dfs(0);
    if (ans == 0)
    {
        cout << "! =" << endl;
        fflush(stdout);
        return;
    }
    if (ans == 1)
    {
        cout << "! >" << endl;
        fflush(stdout);
        return;
    }
    if (ans == -1)
    {
        cout << "! <" << endl;
        fflush(stdout);
        return;
    }
}

signed main()
{
    setvbuf(stdout, NULL, _IONBF, 0);
#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

//
// Created by Administrator on 2026/4/21.
//
