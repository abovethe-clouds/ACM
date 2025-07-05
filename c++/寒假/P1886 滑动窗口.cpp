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
#define int ll
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
int a[1000005], n, m;
void min_make()
{
    deque<int> q;
    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && q.front() <= i - m)
        {
            q.pop_front();
        }
        while (!q.empty( ) && a[q.back()] >= a[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        if(i>=m-1)
            cout << a[q.front()] << " ";
    }
    return;
}
void max_make()
{
    deque<int> q;
    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && q.front() <= i - m)
        {
            q.pop_front();
        }
        while (!q.empty( ) && a[q.back()] <= a[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        if(i>=m-1)
            cout << a[q.front()] << " ";
    }
    return;
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    min_make();
    cout << endl;
    max_make();
    return;
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
    while(t--)
        solve();

    return 0;
}