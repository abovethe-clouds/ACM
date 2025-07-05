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

void solve()
{
    int n, m;
    cin >> n >> m;
    int mp[n][m];
    int maxx = -1;
    vector<pii> point;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            if(mp[i][j]>maxx)
            {
                maxx = mp[i][j];
                point.clear();
                point.push_back(make_pair(i, j));
            }
            else if(mp[i][j]==maxx)
                point.push_back(make_pair(i, j));
        }   
    }
    set<int> one,two;
    for(auto i : point)
    {
        if(i.first!=point[0].first)
            one.insert(i.second);
    }
    if(one.size()<=1)
    {
        cout << mp[point[0].first][point[0].second] - 1 << endl;
        return;
    }
    else
    {
        for(auto i : point)
        {
            if(i.second!=point[0].second)
                two.insert(i.first);
        }
        if(two.size()<=1)
        {
            cout << mp[point[0].first][point[0].second] - 1 << endl;
            return;
        }
    }
    cout << mp[point[0].first][point[0].second] << endl;
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