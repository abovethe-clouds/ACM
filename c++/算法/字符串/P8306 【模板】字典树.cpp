#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn= 4e6+5;
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
int trie[maxn][100],p[maxn],e[maxn],cnt;
void build()
{
    cnt=1;
}
void insert(string s)
{
    int cur=1;
    p[cur]++;
    for (int i = 0; i < s.length(); i++)
    {
        int path=s[i]-'0';
        if(trie[cur][path]==0)
        {
            trie[cur][path]=++cnt;
        }
        cur=trie[cur][path];
        p[cur]++;
    }
    e[cur]++;
    return;
}
int find(string s)
{
    int cur=1;
    for (int i = 0; i < s.length(); i++)
    {
        int path=s[i]-'0';
        if(trie[cur][path]==0)
        {
            return 0;
        }
        cur=trie[cur][path];
    }
    return e[cur];
}
int find_num(string s)
{
    int cur=1;
    for (int i = 0; i < s.length(); i++)
    {
        int path=s[i]-'0';
        if(trie[cur][path]==0)
        {
            return 0;
        }
        cur=trie[cur][path];
    }
    return p[cur];
}
void del(string s)
{
    if(find(s)==0)
        return;
    int cur=1;
    p[cur]--;
    for (int i = 0; i < s.length(); i++)
    {
        int path=s[i]-'0';
        cur=trie[cur][path];
        p[cur]--;
    }
    e[cur]--;
    return;
}
void clear()
{
    for (int i = 0; i <= cnt; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            trie[i][j]=0;
        }
        p[i]=0,e[i]=0;
    } 
    return;
}
void solve()
{
    build();
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        insert(s);
    }
    for (int i = 0; i < m; i++)
    {
        string s;
        cin>>s;
        cout<<find_num(s)<<endl;
    }
    clear();
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