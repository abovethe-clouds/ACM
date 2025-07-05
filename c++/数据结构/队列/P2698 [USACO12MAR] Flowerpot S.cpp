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
int n, d;
pii water[100005];
struct MonotonicQueue{
    int mp[100005] = {};
    int head = 0, end = 0;
    bool is_min = 1;
    MonotonicQueue(bool min_mode = true) : is_min(min_mode) {};
    void push(int x)
    {
        if(end-head==0)
            mp[end++] = x;
        else
        {
            while (((x >= mp[end - 1] && !is_min) || (x <= mp[end - 1] && is_min)) && (end - head) != 0)
                end--;
            mp[end++] = x;
        }
    }
    void giveUp(int x)
    {
        if(mp[head]==x)
            head++;
        return;
    }
    int find()
    {
        if (end - head != 0)
            return mp[head];
        else
            return INT_MAX;
    }
};
bool ok(int x,int y)
{
    return abs(x - y) >= d;
}
void solve()
{
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> water[i].first >> water[i].second;

    sort(water, water + n); 
    MonotonicQueue minn(true), maxx(false);
    int ans = 1e9;
    int l = 0;
    int r = 0;
    while (r < n)
    {
        minn.push(water[r].second);
        maxx.push(water[r].second);
        while (l<r&&ok(minn.find(),maxx.find()))
        {
            if (ok(minn.find(), maxx.find()))
                ans = min(ans, water[r].first-water[l].first);
            minn.giveUp(water[l].second);
            maxx.giveUp(water[l].second);
            l++;
        }
        r++;
    }
    
    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        freopen("test.in", "r", stdin);
       // freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    while(t--)
        solve();

    return 0;
}