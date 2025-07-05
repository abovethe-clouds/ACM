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
priority_queue<ll> q;
ll n,cnt;
void solve()
{
    cin>>n;
    ll sum=0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        sum+=a;
        q.push(a);
    }
    // while (1)
    // {
    //     int a=q.top();
    //     if(a==0)
    //         break;
    //     q.pop();
    //     int b=q.top();
    //     if(b==0)
    //         break;
    //     q.pop();
    //     a--;
    //     b--;
    //     cnt++;
    //     q.push(a);
    //     q.push(b);
        
    // }
    // cout<<cnt;
    if(q.top()>sum-q.top())
        cout<<sum-q.top();
    else
        cout<<sum/2;
    
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