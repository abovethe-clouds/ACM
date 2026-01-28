#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef pair<int,int> pii;
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
    int n=read(),k=read(),l=read(),r=read();
    vector<int> v(n),cnt(2e5+5,0);
    for(int i=0;i<n;i++)
    {
        v[i]=read();
    }
    int i=-1,j=-1,ans=0,cur=0;
    while (true)
    {
        while (j+1<n&&(cur<k||(cur==k&&cnt[v[j+1]]>0)))
        {
            j++;
            if (cnt[v[j]]==0)
                cur++;
            cnt[v[j]]++;
        }
        if (cur<k)
            break;
        while (i<j&&cur==k)
        {
            i++;
            cnt[v[i]]--;
            if (cnt[v[i]]==0)
                cur--;
        }
        int len=j-i;
        if (len>=l&&len<=r)
            ans++;
    }
    cout<<ans<<endl;
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
    t = read();
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2026/1/22.
//