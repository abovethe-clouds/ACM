#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=1e6+5;

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
int a[maxn] = {}, b[maxn] = {}, low[maxn] = {}, hig[maxn] = {};
void solve()
{
    int n,m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    low[0] = a[0], hig[n-1] = b[n-1];
    for (int i = 1; i < n; i++)
    {
        low[i] = max(low[i - 1], a[i]);
    }
    if (hig[n-1] < low[n-1])
    {
        cout << "NO" << endl;
        return;
    }
    for (int i = n-2; i >= 0; i--)
    {
        hig[i] = min(hig[i + 1], b[i]);
        if(hig[i]<low[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    int sum_min = 0, sum_max = 0;
    for (int i = 0; i < n; i++)
    {
        sum_min += low[i];
        sum_max += hig[i];
    }
    if (m >= sum_min && m <= sum_max)
    {
        cout << "YES" << endl;
        return;
    }
    else
        cout << "NO" << endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        // freopen("test.in", "r", stdin);
        // freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}