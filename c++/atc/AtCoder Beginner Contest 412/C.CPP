#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
#define int ll
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
    int n;
    cin >> n;
    pii mp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> mp[i].first;
        mp[i].second = i;
    }
    if(n==2)
    {
        if(mp[0].first*2>=mp[1].first)
            cout << "2" << endl;
        else
            cout << -1 << endl;
        return;
    }
    if (mp[0].first * 2 >= mp[n-1].first)
    {
        cout << "2" << endl;
        return;
    }
    sort(mp, mp + n);
    int begin, end;
    for (int i = 0; i < n; i++)
    {
        if(mp[i].second==0)
        {
            begin = i;
        }
        if (mp[i].second == n-1)
        {
            end = i;
            break;
        }
    }
    vector<int> use;
    for (int j = begin;j <= end;j++)
    {
        use.push_back(mp[j].first);
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < use.size(); )
    {
        auto a = lower_bound(use.begin(), use.end(), use[i] * 2)- use.begin();
        if(a>=use.size())
            break;
        if (use[a] == 2 * use[i])
        {
            i = a;
            cnt1++;
        }
        else
        {
            if (a - 1 == i)
            {
                cnt1 = -1;
                break;
            }
            else
            {
                i = a-1;
                cnt1++;
            }
        }
    }
    for (int i = use.size()-1; i >= 0; )
    {
        auto a = lower_bound(use.begin(), use.end(), ceil(use[i] / 2.0)) - use.begin();
        if (a >= use.size())
            break;
        if(a==i)
        {
            cnt2 = -1;
            break;
        }
        if(use[a]*2>=use[i])
        {
            i = a;
            cnt2++;
        }
    }
    if (cnt1 == cnt2 &&cnt1 == -1)
    {
        cout << -1 << endl;
        return;
    }
    if (cnt1 == -1)
    {
        cout << cnt2 + 2 << endl;
        return;
    }
    if (cnt2 == -1)
    {
        cout << cnt1 + 2 << endl;
        return;
    }
    cout << min(cnt1, cnt2) + 2 << endl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        freopen("test.in", "r", stdin);
       // freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
//23ac wa 9