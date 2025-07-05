#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 2e5+5;
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
int n,mann=-1,sum=0,v[maxn]={};
vector<int> mp[maxn];
void solve()
{
    cin>>n;
    for (int i = 0; i < n-1; i++)
    {
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if(mp[i].size()==1)
            continue;
        if(mp[i].size()==2)
        {
            mann=max(v[mp[i][0]]*v[mp[i][1]],mann);
            sum+=2*v[mp[i][0]]*v[mp[i][1]];
            sum%=10007;
            continue;
        }
        ll w=0,w1=0;
        int a=-1,b=-1;
        for (auto p : mp[i])
        {
            w+=v[p];
            w1+=v[p]*v[p];
            if(v[p]>a)
            {
                b=a;
                a=v[p];
            }
            else
            {
                if(v[p]>b)
                    b=v[p];
            }
        }   
        w*=w;
        w-=w1;
        w%=10007;
        sum+=w;
        sum+=10007;
        sum%=10007;
        mann=max(a*b,mann);
    }
    cout<<mann<<" "<<sum;
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