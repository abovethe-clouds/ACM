#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int long long
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
string s="kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th";
bool check(int l,int r)
{
    int len=r-l+1;
    if (!(len>=8&&len<=16))
    {
        return false;
    }
    bool is_digit=false,is=false;
    for (int i=l; i<=r; i++)
    {
        if (s[i]>='0'&&s[i]<='9')
            is_digit=true;
        else if (!((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')))
            is=true;
    }
    return is&&is_digit;
}
void solve()
{
    int ans=0;
    for (int i=0;i<s.length();i++)
    {
        for (int j=i+1;j<s.length();j++)
        {
            if (check(i,j))
            {
              ans++;

            }
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    while (t--)
        solve();
    return 0;
}
