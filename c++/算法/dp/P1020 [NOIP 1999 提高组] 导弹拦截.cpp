#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=1e5+5;
int dp1[maxn],dp2[maxn];//dp1 最长非上升子序列 dp2 最长不下降子序列
void solve()
{
    vector<int> q;
    int a;
    while (cin>>a)
    {
        q.push_back(a);
    }
    int n=q.size();
    dp1[1]=dp2[1]=q[0];
    int r1=1,r2=1;
    for (int i = 1; i < n; i++)//i长度
    {
        //最长不升子序列  以i长度的最大的尾巴是多少，后面就能更好的加元素了 {10,9,8,7,5} add6 {10,9,8,7,6}
        if(q[i]<=dp1[r1]) 
        {
            r1++;
            dp1[r1]=q[i];
        } 
        else
            *upper_bound(dp1+1,dp1+r1+1,q[i],greater<int>())=q[i];


        //最长不降子序列 {1 2 3 4 7} add 6  {1 2 3 4 6}  {1 2 3}  add9 {1 2 3 9}
        if(dp2[r2]<q[i])
        {
            r2++;
            dp2[r2]=q[i]; 
        }
        else
            *lower_bound(dp2+1,dp2+r2+1,q[i])=q[i];

    }
    cout<<r1<<endl<<r2;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> q;
    #ifndef ONLINE_JUDGE 
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
}