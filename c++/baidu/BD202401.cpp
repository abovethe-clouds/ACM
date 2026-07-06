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
struct Cmp {
    bool operator()(pii a, pii b) const {
        if(a.first+a.second!=b.first+b.second)
            return a.first+a.second < b.first+b.second;
        return a < b;
    }
};
void solve()
{
    int n,b;
    cin>>n>>b;
    vector<pii> a(n);
    set<pii,Cmp> st;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
        st.insert(a[i]);
    }
    int ans=0;
    for (auto i:a)
    {
        st.erase(i);
        pii o1=i;
        o1.first/=2;
        st.insert(o1);
        int sum=0,cnt=0;
        for (const auto & [fst, snd] : st)
        {
            if (sum+fst+snd<=b)
            {
                sum+=fst+snd;
                cnt++;
            }
            else
                break;
        }
        st.erase(o1);
        st.insert(i);
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
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
// Created by Administrator on 2026/5/28.
//