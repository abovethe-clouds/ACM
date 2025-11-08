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
    int l,k;
    cin>>l>>k;
    string s;
    cin>>s;
    vector<int> v;
    k=min(k,7ll);
    int next[8]={-1,0,0,1,0,0,1,0};
    string s2="nanjing";
    for(int i=0;i<=k;i++)
    {
        int ans=0;
        int x=0,y=0;
        while (x<s.length())
        {
            while(x<s.length()&&y<s2.length())
            {
                if(s[x]==s2[y])
                    x++,y++;
                else if(y==0)
                    x++;
                else
                    y=next[y];
            }
            if (y==s2.length())
            {
                ans++;
                y=0;
            }
        }
        v.push_back(ans);
        rotate(s.begin(), s.begin() + 1, s.end());
    }
    sort(v.begin(),v.end());
    cout<<v.back()<<endl;

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
    cin>>t;
    while (t--)
        solve();
    return 0;
}
