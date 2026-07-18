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
ull lowbit(ull x)
{
    return x & -x;
}
int cnt_2(ull x)
{
    int cnt = 0;
    for (int i = 0; i < 64; i++)
    {
        if (x >> i & 1)
            cnt++;
    }
    return cnt;
}
int max_bit(ull x)
{
    int maxx = 0;
    for (int i = 0; i < 64; i++)
    {
        if (x >> i & 1)
        {
            maxx = i;
        }
    }
    return maxx;
}
int low_1(ull x)
{
    int ans = 0;
    while ((x & 1) == 0)
    {
        ans++;
        x >>= 1;
    }
    return ans;
}
ull built(int x,ull y)
{
    int i = low_1(y);
    ull ans = 0;
    for (int u=0; u < x; u++)
    {
        ans |= (1ULL <<( u + i));
    }
    return ans;
}
void solve()
{
    ull n, x, y;
    cin >> n >> x >> y;
    int cnt_x = cnt_2(x), cnt_y = cnt_2(y);
    if(x==y)
    {
        cout << 0 << endl;
        return;
    }
    if(lowbit(x)==lowbit(y)||cnt_x==cnt_y)
    {
        cout << 1 << endl;
        return;
    }
    
    else
        cout << 2 << endl;
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