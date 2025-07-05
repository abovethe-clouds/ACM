#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const ll mod1 = 19260817,mod2 = 19660813,base=12222222231;
struct st
{
    ll hash1,hash2;
    bool operator<(const st &x) 
        {return x.hash1<hash1;}
}tree[10005];
ll hash1(string s)
{
    ll ans=0;
    for (int i = 0; i < s.length(); i++)
    {
        ans=(ans*base+int(s[i]))%mod1;
    }
    return ans;
}
ll hash2(string s)
{
    ll ans=0;
    for (int i = 0; i < s.length(); i++)
    {
        ans=(ans*base+int(s[i]))%mod2;
    }
    return ans;
}
void solve()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        tree[i].hash1=hash1(s);
        tree[i].hash2=hash2(s);
    }
    sort(tree,tree+n);
    int cnt=1;
    for (int i = 1; i < n; i++)
    {
        if(tree[i].hash1!=tree[i-1].hash1||tree[i].hash2!=tree[i-1].hash2)
            cnt++;
    }
    cout<<cnt;
    
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