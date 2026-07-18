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
bool check(vector<int> &v,int m,int mid)
{
    for (int i=1;i<v.size();i++)
    {
        int len=v[i]-v[i-1];
        if (len>mid)
        {
            if (m==0)
            {
                return false;
            }
            int cnt=ceil((len*1.0)/mid)-1;
            if (cnt<=m)
            {
                m-=cnt;
            }
            else
                return false;
        }
    }
    return true;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    m++;
    v.push_back(0);
    sort(v.begin(),v.end());
    int l=0,r=v[n-1]-v[0];
    while (l<r)
    {
        int mid = (l+r)>>1;
        if(check(v,m,mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<max(l,1ll)<<endl;
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