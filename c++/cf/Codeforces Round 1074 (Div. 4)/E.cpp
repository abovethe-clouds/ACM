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

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n),judge(m); // 机器人位置 , 坏位置
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
    {
        cin >> judge[i];
    }
    sort(judge.begin(),judge.end());
    string s; // 指令
    cin >> s;
    vector<int> move_l(k,0), move_r(k,0),dead_cnt(k+1); // 记录每一步向左和向右移动的最远距离, 死亡机器人数量(后续前缀和)
    int where = 0; // 当前位置

    for (int i = 0; i < k; i++)
    {
        if (s[i] == 'L')
        {
            where--;
            move_l[i] = min(where, move_l[max(i - 1,0ll)]);
            move_r[i] = move_r[max(i - 1,0ll)];
        } else
        {
            where++;
            move_r[i] = max(where, move_r[max(i - 1,0ll)]);
            move_l[i] = move_l[max(i - 1,0ll)];
        }
    }
    auto b=[=](int l,int r)
    {
        auto it=lower_bound(judge.begin(),judge.end(),l);
        if(it==judge.end())
            return false;
        if (*it>r)//不在范围，没死
            return false;
        return true;
    };
    for (int i=0;i<n;i++)
    {
        int l=0,r=k;//二分找死亡位置
        while (l<r)
        {
            int mid=(l+r)/2;
            int where_l=a[i]+move_l[mid];
            int where_r=a[i]+move_r[mid];
            if (b(where_l,where_r))
            {
                r=mid;
            }
            else
                l=mid+1;
        }
        dead_cnt[l]++;
    }
    for (int i=1;i<k;i++)
    {
        dead_cnt[i]+=dead_cnt[i-1];
    }
    for (int i=0;i<k;i++)
        cout<<n-dead_cnt[i]<<" ";
    cout<<endl;
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
    cin >> t;
    while (t--)
        solve();
    return 0;
} //
// Created by Administrator on 2026/1/18.
//
