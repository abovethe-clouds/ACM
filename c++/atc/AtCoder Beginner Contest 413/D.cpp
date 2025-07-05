#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
// #define endl "\n"
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
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}
bool cmp(int x, int y)
{
    x = abs(x);
    y = abs(y);
    return x < y;
}
int a[200006]={};
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if(n==2)
    {
        cout << "Yes" << endl;
        return;
    }
    sort(a, a + n, cmp);
    bool flag = 1;
    for (int i = 0; i < n-2; i++)
    {
        __int128_t oo = 1;
        if(a[i+2]*oo*a[i]!=a[i+1]*oo*a[i+1])
        {
            flag = 0;
        }
    }
    if(flag)
        cout << "Yes" << endl;
    else
    {
        int a1 = 0, b1 = 0;
        for (int i = 0; i < n; i++)
        {
            if(a[i]==a[0])
                a1++;
            if(a[i]==-1*a[0])
                b1++;
        }
        if(a1+b1==n&&(abs(a1-b1)<=1))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
// #ifndef ONLINE_JUDGE
//     freopen("test.in", "r", stdin);
//     freopen("test.out", "w", stdout);
// #endif
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}