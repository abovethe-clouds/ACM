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
    int a[n];
    int r, l;
    cin >> a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i]; 
    }
    if(n==1)
    {
        cout << "NO" << endl;
        return;
    }
    bool flag = 1;
    for (int i = 1; i < n; i++)
    {
        if(a[i-1]<=a[i])
            continue;
        else
        {
            l = i - 1;
            r = i;
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << 2 << endl << a[l] << " " << a[r] << endl;
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
       // freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}