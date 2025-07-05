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
    int n,m;
    priority_queue<int> maxq;
    priority_queue<int,vector<int>,greater<int>> minq;
    map<int,int> mp;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        mp[a]++;
        maxq.push(a);
        minq.push(a);
    }
    while (m)
    {
        if(mp[maxq.top()]>mp[minq.top()])
        {
            //cout<<1<<endl;
            m-=mp[minq.top()];
            //mp[minq.top()]=0;
            //int a=minq.top();
            while (mp[minq.top()]--)
            {
                minq.pop();
            }
        }
        else
        {
            //cout<<2<<endl;
            m-=mp[maxq.top()];
            //mp[maxq.top()]=0;
            //int a=maxq.top();
            while (mp[maxq.top()]--)
            {
                maxq.pop();
            }
        }
    }
    cout<<maxq.top()-minq.top()<<endl;
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t --)
        solve();

    return 0;
}