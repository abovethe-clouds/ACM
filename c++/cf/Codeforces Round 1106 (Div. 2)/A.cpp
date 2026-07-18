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
bool judge(vector<int> a,vector<int> b)
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for (int i=0;i<a.size();i++)
    {
        if (a[i]<b[i])
            return false;
    }
    return true;
}
void solve()
{
    int n,c;
    cin>>n>>c;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    if (!judge(a,b))
    {
        cout<<-1<<endl;
        return;
    }
    int spent1=0,spent2=0;
    {
        for (int i=0;i<n;i++)
        {
            if (a[i]>=b[i])
                spent1+=a[i]-b[i];
            else
            {
                spent1=inf;
                break;
            }
        }
    }
    {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for (int i=0;i<n;i++)
        {
                spent2+=a[i]-b[i];
        }
    }
    cout<<min(spent1,spent2+c)<<endl;
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
    cin >> t;
    while (t--)
        solve();
    return 0;
}
