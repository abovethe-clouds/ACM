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
bool judge(int a,int b,int c)
{
    return a+b>c && a+c>b && b+c>a;
}
void solve()
{
    int x=read();
    for (int i=0;i<=30;i++)
    {
        for (int j=0;j<=30;j++)
        {
            int y=(1<<i)|(1<<j);
            if (y<x&&judge(x,y,x^y))
            {
                cout<<y<<endl;
                return;
            }

        }
    }
    cout<<-1<<endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //     freopen("test.in", "r", stdin);
    //     freopen("test.out", "w", stdout);
    // #endif
    int t = 1;
    t=read();
    while(t--)
        solve();

    return 0;
}