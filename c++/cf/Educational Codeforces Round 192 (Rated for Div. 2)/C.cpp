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
int sum(vector<int>& v)
{
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
        ans += v[i];
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> cnt;
    cnt.push_back(1);
    for (int i = 1; i < n; i++)
    {
        if (v[i] == v[i - 1])
            cnt.back()++;
        else
            cnt.push_back(1);
    }
    sort(cnt.begin(), cnt.end());
    int ans=0,m=cnt.size();
    for (int i = 0; i < cnt.size(); i++)
    {
        int j=i;
        while (j<cnt.size()&&cnt[j]==cnt[i])
            j++;
        n-=(cnt[i]-1)*(m);
        if (n<=k&&(k-n)%m==0)
            ans++;
        n-=m;
        for (int k=j;k<cnt.size();k++)
            cnt[k]-=cnt[i];
        m-=j-i;
        i=j-1;
    }
    cout << ans << endl;
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
    cin >> t;
    while (t--)
        solve();
    return 0;
}

//
// Created by Administrator on 2026/7/6.
//