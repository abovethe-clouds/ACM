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
int fa[1005];
int n, m;
void build()
{
    for (int i = 0; i < 1005; i++)
    {
        fa[i] = i;
    }
    return;
}
bool judge()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if(fa[i]==i)
            cnt++;
    }
    if(cnt==1)
        return 1;
    return 0;
}
int find(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x] = find(fa[x]);
}
void merge(int x,int y)
{
    fa[find(x)] = find(y);
}
struct work
{
    int time, b, e;
};
bool cmp(work a,work b)
{
    return a.time < b.time;
}
void solve()
{
    build();
    cin >> n >> m;
    vector<work> works;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        work o = {c, b, a};
        works.push_back(o);
    }
    sort(works.begin(), works.end(), cmp);
    for (int i = 0; i < m; i++)
    {
        merge(works[i].b, works[i].e);
        if(i!=m-1)
        {
            
            if(works[i].time!=works[i+1].time)
            {
                if(judge())
                {
                    cout << works[i].time;
                    return;
                }
            }
        }
    }
    if(judge())
    {
        cout << works[m-1].time;
        return;
    }
    cout << -1;
    return;
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