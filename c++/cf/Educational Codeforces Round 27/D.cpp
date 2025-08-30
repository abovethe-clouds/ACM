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
    int n=read();
    stack<int> speed;
    int op,v,cnt=0,Overtake=0;
    while (n--)
    {
        op=read();
        switch (op)
        {
            case 1:
                v=read();
                if (speed.empty())
                    break;
                while (!speed.empty()&&speed.top()<v)
                {
                    speed.pop();
                    cnt++;
                }
                break;
            case 2:
                cnt+=Overtake;
                Overtake=0;
                break;
            case 6:
                Overtake++;
                break;
            case 4:
                Overtake=0;
                break;
            case 3:
                speed.push(read());
                if (v>speed.top())
                {
                    cnt++;
                    speed.pop();
                }
                break;;
            case 5:
                while (speed.empty()==false)
                    speed.pop();
        }
    }
    cout<<cnt;
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
// Created by Administrator on 2025/8/28.
//