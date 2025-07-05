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
int fa[5005];
int find(int x)
{
    if(fa[x]==x)
        return x;
    else return find(fa[x]);
}
void solve()
{
    int n,m,p;
    cin>>n>>m>>p;
    for (int i = 0; i < n+1; i++)
    {
        fa[i]=i;
    }
    for (int  i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        fa[find(a)]=find(b);
    }
    for (int i = 0; i < p; i++)
    {
        int a,b;
        cin>>a>>b;
        if(find(a)==find(b))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    

    
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