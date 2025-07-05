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
const int dx[8] = {-1,0,1,0,-1,-1,1,1}, dy[8] = {0,1,0,-1,-1,1,-1,1};
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
    int n,m;
    cin>>n>>m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<abs(m-a[0])<<endl;
        return;
    }
    if(m>=a[n-1])
    {
        cout<<m-a[0]<<endl;
        return;
    }
    if(m<=a[0])
    {
        cout<<a[n-1]-m<<endl;
        return;
    }
    if(abs(a[n-1]-m)>abs(a[0]-m))
    {
        cout<<abs(a[0]-m)*2+abs(a[n-1]-m)<<endl;
        return;
    }
    cout<<abs(a[n-1]-m)*2+abs(a[0]-m)<<endl;
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
    cin >> t;
    while(t--)
        solve();

    return 0;
}