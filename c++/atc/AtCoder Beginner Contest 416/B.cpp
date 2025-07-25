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
    string s;
    cin >> s;
    char make[s.length()+3] = {};
    for (int i = 0; i < s.length(); i++)
    {
        make[i] = '.';
    }
    bool ok = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='#')
        {
            make[i] = '#';
            if(!ok)
            {
                make[i + 1] = 'o';
                if(i>=1)
                    make[i - 1] = 'o';
                ok = 1;
            }
            else
                make[i + 1] = 'o';
        }
    }
    if(!ok)
        make[s.length() - 1] = 'o';
    for (int i = 0; i < s.length(); i++)
    {
        cout << make[i];
    }
    
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
    //cin >> t;
    while(t--)
        solve();

    return 0;
}