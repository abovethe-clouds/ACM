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
void solve()
{
    string s;
    vector<pii> a;
    int cnt=0;
    a.clear();
    cin>>s;
    int l=s.length();
    for (int i = 0; i < l-3; i++)
    {
        if(s[i]=='b'&&s[i+1]=='u'&&s[i+2]=='c'&&s[i+3]=='t')
            a.push_back(make_pair(i,i+3));
    }
    for (auto i: a)
    {
        int q=i.first;
        int h=i.second;
        cnt+=(q+1)*(l-1-h+1);

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