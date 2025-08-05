#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    string s ;
    cin >> s;
    pii ansf={0,-1},anse={0,-1};
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
            ans-=a[i];
        else
            ans+=a[i];
        if (ans<ansf.first)
        {
            ansf.first = ans;
            ansf.second = i;
        }
    }
    ans=0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] == 'A')
            ans-=a[i];
        else
            ans+=a[i];
        if (ans<anse.first)
        {
            anse.first = ans;
            anse.second = i;
        }
    }
    int l,r;
    if (ansf.first>anse.first)
    {
        l=anse.second;
        r=n-1;
    }
    else
    {
        l=0;
        r=ansf.second;
    }
    for (int i = l; i <= r; i++)
    {
        if (s[i] == 'A')
            s[i]='B';
        else
            s[i]='A';
    }
    int sum=0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'B')
            sum+=a[i];

    }
    cout << sum << endl;

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
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
