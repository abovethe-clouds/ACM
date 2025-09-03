#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second

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
pii U(pii x,int l)
{
    x.first-=l;
    return x;
}
pii D(pii x,int l)
{
    x.first+=l;
    return x;
}
pii R(pii x,int l)
{
    x.second+=l;
    return x;
}
pii L(pii x,int l)
{
    x.second-=l;
    return x;
}
bool operator==(const pii &a,const pii &b)
{
    return a.second==b.second&&a.first==b.first;
}
bool judge(pii x,pii y)
{
    return abs(x.first-y.first)==abs(x.second-y.second);
}
void solve()
{
    pii t,a,whereT={0,0},whereA={0,0};
    cin>>t.first>>t.second>>a.first>>a.second;
    int n,m,l;
    cin>>n>>m>>l;
    pair<char,int> T[m],A[l];
    for(int i=0;i<m;i++)
    {
        cin>>T[i].first>>T[i].second;
    }
    for(int i=0;i<l;i++)
    {
        cin>>A[i].first>>A[i].second;
    }
    int ans=0;
    if (t==a||judge(a,t))
    {
        if (t==a)
        {
            if (T[whereA.first]==A[whereT.first])
            {
                ans=
            }
        }
    }
    else
    {

    }


}

int main()
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