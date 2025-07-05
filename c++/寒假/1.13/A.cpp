#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int N = 1e5, M = N * 2, mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
int t = 1;int s;
priority_queue<int, vector<int>, greater<int>> ji,ou;
void solve()
{
    int n,a;
    cin>>n;
    
    for (int i = 1; i <= n; i++)
    {
        
        if(i%2==0)
            ou.push(i);
        else
            ji.push(i);
    }
    if(t!=s-1)
    {   
        cout<<endl;
        while(!ji.empty())
        {
            cout<<ji.top()<<" ";
            ji.pop();
        }
        cout<<endl;
        while(!ou.empty())
        {
            cout<<ou.top()<<" ";
            ou.pop();
        }
        
        return;
    }
    else
    {
        while(!ji.empty())
        {
            cout<<ji.top()<<" ";
            ji.pop();
        }
        cout<<endl;
        while(!ou.empty())
        {
            cout<<ou.top()<<" ";
            ou.pop();
        }
        
        return;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    
    cin >> t;
    s=t;
    while(t --)
        solve();

    return 0;
}


