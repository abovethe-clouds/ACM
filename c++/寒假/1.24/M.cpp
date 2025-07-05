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
vector<int> map1[100000];
int re[100000];
int n,p,c,t;
void solve()
{
    cin>>n>>p>>c>>t;
    int max1=0;
    while(p--)
    {
        int a,b;
        cin>>a>>b;
        map1[a].push_back(b);
        map1[b].push_back(a);
    }
    re[c]=1;
    queue<int> oo;
    oo.push(c);
    while (!oo.empty())
    {
        int a=oo.front();
        oo.pop();
        for(auto i:map1[a])
        {
            if(re[i]==0)
            {
                oo.push(i);
                re[i]=re[a]+1;
                max1=max(max1,re[i]);
            }
        }
    }
    cout<<max1+t;

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