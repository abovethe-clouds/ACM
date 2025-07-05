#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const ll mod1 = 19260817,mod2 = 19660813, base=131;
map<pair<string,string>,int> t;
void solve()
{
    int n,cnt=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string s1,s2,s3="";
        cin>>s1>>s2;
        s3+=s1[0];
        s3=s3+s1[1];
        if(s2==s3)
            continue;
        pair<string,string> p=make_pair(s3,s2),p1=make_pair(s2,s3);//s3城市 s2州
        cnt+=t[p];
        t[p1]++;
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