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
    int n;
    cin>>n;
    vector<int> q;
    int a;
    while(cin>>a)
    {
        q.push_back(a);
    }
    while(l<r)
    {
        int mid=(l+r)/2;//找最大的，然后知道\走的  r l 是什么 以r,l结尾嘛
        if()
            r=mid;
        else
            l=mid+1;
    }
    

    //第二问，LIS的size
    
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
}