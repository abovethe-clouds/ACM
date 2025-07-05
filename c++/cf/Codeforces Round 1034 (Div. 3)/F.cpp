#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
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
    int a[n+1];
    bool vis[n + 1] = {};
    for (int i = 0; i <= n; i++)
    {
        a[i] = i;
    }
    for (int i = 2; i < n+1; i++)
    {
        if(vis[i])
            continue;
        for (int j = 2; j*i < n+1; j++)
        {
            if(vis[i*j]==0)
            {
                swap(a[i], a[i * j]);
                
                vis[i] = 1;
                break;
            }
        } 
    }
    for (int i = 1; i < n+1; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        //freopen("test.in", "r", stdin);
       // freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}