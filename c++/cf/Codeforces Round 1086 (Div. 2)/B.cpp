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

void solve()
{
    int n,k,m,p;
    cin>>n>>k>>p>>m;
    vector<int> v(n);
    for(int i = 0;i < n;i++)
    {
        cin>>v[i];
    }
    p--;
    int value=v[p];
    v[p]=-1;
    priority_queue<int,vector<int>,greater<int> >q;
    queue<int> qq;
    for(int i = 0;i < k;i++)
    {
        q.push(v[i]);
    }
    for (int i=k;i<n;i++)
    {
        qq.push(v[i]);
    }
    int cnt=0;
    while ((q.top()==-1&&m>=value)||(q.top()!=-1&&m>=q.top()))
    {
        if (q.top()==-1)
        {
            cnt++;
            m-=value;
        }
        else
            m-=q.top();
        qq.push(q.top());
        q.pop();
        q.push(qq.front());
        qq.pop();
    }
    cout<<cnt<<endl;



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
