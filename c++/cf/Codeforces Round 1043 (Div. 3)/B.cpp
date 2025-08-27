#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
//#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;

ll read()
{
    ll x = 0, w = 1;
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
    ull n=read();
    bool flag=false;
    int len=to_string(n).length();
    priority_queue<ull,vector<ull>,greater<ull>> q;
    for(ull i=10;i<pow(10ULL,len*1ULL);i*=10)
    {
        i++;
        if (n%i==0)
        q.push(n/i);
        i--;
    }
    int x=q.size();
    if(x==0)
    {
        cout<<x<<endl;
        return;
    }
    else
    {
        cout<<x<<endl;
        while(q.empty()==false)
        {
            cout<<q.top()<<" ";
            q.pop();
        }
    }
    cout<<endl;

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
    int t = read();
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
