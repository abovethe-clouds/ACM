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
    int n,mm;
    bool have_0=false;
    cin>>n>>mm;
    vector<int> num1,num2;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if (x==0)
            have_0=true;
        else
        {
            if (x>0)
                num1.push_back(x);
            else
                num2.push_back(-x);
        }
    }
    sort(num1.begin(),num1.end());
    sort(num2.begin(),num2.end());
    int ans_max=0;
    for(int i=0;i<num1.size();i++)
    {
        int m=mm;
        if (num1[i]<=m)
        {
            int ans=i+1;
            m-=2*num1[i];
            m=max(0ll,m);
            auto it=upper_bound(num2.begin(),num2.end(),m);
            if (it!=num2.begin())
            {
                --it;
                ans+=it-num2.begin()+1;
            }
            ans_max=max(ans_max,ans);
        }
        else
            break;
    }
    for(int i=0;i<num2.size();i++)
    {
        int m=mm;
        if (num2[i]<=m)
        {
            int ans=i+1;
            m-=2*num2[i];
            m=max(0ll,m);
            auto it=upper_bound(num1.begin(),num1.end(),m);
            if (it!=num1.begin())
            {
                --it;
                ans+=it-num1.begin()+1;
            }
            ans_max=max(ans_max,ans);
        }
        else
            break;
    }
    cout<<ans_max+have_0;
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
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2026/5/2.
//