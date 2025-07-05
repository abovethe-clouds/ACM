#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e8 - 3, inf = 0x3f3f3f3f, P = 131;
const int dx[8] = {-1,0,1,0,-1,-1,1,1}, dy[8] = {0,1,0,-1,-1,1,-1,1},maxn=1e5+5;
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
int n,c[maxn],cnt=0;
pii a1[maxn], a2[maxn];
void my_sort(int l,int r)
{
    if(l==r)
        return;
    int mid = (l + r) / 2;
    my_sort(l, mid);
    my_sort(mid + 1, r);
    int d[r - l + 1], i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (c[i] > c[j])
        {
            d[k++] = c[j++];
            cnt += mid - i + 1;
            cnt %= mod;
        }
        else
            d[k++] = c[i++];
    }
    while (i <= mid)
    {
        d[k++] = c[i++];
    }
    while (j <= r)
    {
        d[k++] = c[j++];
    }
    for (int i = 0; i < r-l+1; i++)
    {
        c[l + i] = d[i];
    }
    return;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a1[i].first;
        a1[i].second = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a2[i].first;
        a2[i].second = i;
    }
    sort(a1 + 1, a1 + 1 + n);
    sort(a2 + 1, a2 + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        c[a2[i].second] = a1[i].second;
    }
    my_sort(1, n);
    cout << cnt;
}

signed main()
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