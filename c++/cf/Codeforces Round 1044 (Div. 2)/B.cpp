#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=2e5+5;

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
int fa[maxn];
int find(int i)
{
    if(fa[i]==i)
        return i;
    return fa[i]=find(fa[i]);
}
void merge(int x,int y)
{
    fa[find(x)]=find(y);
}
void solve()
{
    const int n=read();
    vector<int> v(n);


    for(int i=0;i<n;i++)
        v[i]=read();
    if (n==2)
    {
        cout<<max(v[0],v[1])<<'\n';
        return;
    }
    sort(v.begin(), v.end());
    ll sum=0;
    if(n%2==0)
    {
        for(int i=1;i<n;i+=2)
            sum+=v[i];
    }
    else
    {
        for(int i=0;i<n;i+=2)
            sum+=v[i];
    }
    cout<<sum<<'\n';

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
    int t = read();

    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2025/8/24.
//