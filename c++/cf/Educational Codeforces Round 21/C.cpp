#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, pair<int,int>> pii;
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
    const int N = read();
    int m=read(),sum=0;
    vector<pii> a(N);
    for (int i = 0; i < N; i++)
    {
        a[i].first = read();
        a[i].second.second = i;
        a[i].second.first =(a[i].first+1)/2;
        sum += a[i].second.first;
    }
    if (sum>m)
    {
        cout<<-1<<endl;
        return;
    }
    m-=sum;
    sort(a.begin(), a.end());
    for (int i = N - 1; i >= 0; --i)
    {
        int cha=a[i].first-a[i].second.first;
        if (cha>=m)
        {
            a[i].second.first += m;
            break;
        }
        else
        {
            a[i].second.first = a[i].first;
            m-=cha;
        }
    }
    sort(a.begin(), a.end(),[](pii a,pii b){return a.second.second<b.second.second;});
    for (int i=0; i < N; i++)
        cout<<a[i].second.first<<" ";
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
// Created by Administrator on 25-8-20.
//
