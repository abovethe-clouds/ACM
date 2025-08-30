#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
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
#define int ll
struct my_deque
{

};
void solve()
{
    int n;
    deque<int> A,B;
    string s;
    cin>>n>>s;

    for(int i=0;i<n*2;i++)
    {
        if(s[i]=='A')
            A.push_back(i+1);
        else if(s[i]=='B')
            B.push_back(i+1);
    }
    int ans1=0,ans2=0;
    for (int i=1;i<=n;i++)
    {
        if (A[i-1]!=i*2)
        {
            ans1+=abs(A[i-1]-(i*2));
        }
    }
    for (int i=1;i<=n;i++)
    {
        if (B[i-1]!=i*2)
        {
            ans2+=abs(B[i-1]-(i*2));
        }
    }
    cout<<min(ans1,ans2)<<'\n';

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2025/8/30.
//