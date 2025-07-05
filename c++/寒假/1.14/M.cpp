#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int N = 1e5, M = N * 2, mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
stack <int> oh;
int n,x;
void hhh(int oo)
{
    if(oo<x)
    {
        oh.push(oo);
    }
    else
    {
        oh.push(oo%x);
        hhh(oo/x);
    }
}
void solve()
{
    cin>>n>>x;
    hhh(n);
    while (!oh.empty())
    {
        int a=oh.top();
        oh.pop();
        if(a>=0&&a<=9)
            cout<<a;
        else
            cout<<char(a-10+'A');
    }
    
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