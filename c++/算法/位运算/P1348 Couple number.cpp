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
void judge(int x)
{
    for(int i=0;i<=1000;i++)
    {
        if(int(sqrt(x+i*i))*int(sqrt(x+i*i))==x+i*i)
        {
            cout<<x<<" "<<sqrt(x+i*i)<<" "<<i<<endl;
            return;
        }
    }
    //cout<<x<<" 0"<<endl;
    return;
}
void solve()
{
    int a,b,ans=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    {
        if(((i-1)%4==0 )||((i+1)%4==0) ||(i%4==0))
            ans++;
    }   
    cout<<ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        freopen("test.in", "r", stdin);
        //freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    while(t--)
        solve();

    return 0;
}