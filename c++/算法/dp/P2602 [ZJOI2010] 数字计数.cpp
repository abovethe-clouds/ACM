#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
#define int long long
typedef unsigned long long ull;
typedef pair<int, int> pii;
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
void sol(int x,int ans[10])
{
    if (x==0)
    {
        ans[0] = 1;
        return;
    }
    vector<int> v;
    int len=0;
    while (x != 0)
    {
        v.push_back(x%10);
        x = x/10;
        len++;
    }
    reverse(v.begin(),v.end());
    for (int i=0;i<len;i++)
    {
        int high=0,low=0,pow=1;
        for (int j = 0; j < i; ++j)
        {
            high = high*10+v[j];
        }
        for (int j = i+1; j < len; ++j)
        {
            low = low*10+v[j];
            pow = pow*10;
        }

        for (int j = 0; j <= 9; ++j)
        {
            int sum = 0;
            if (j<v[i])
                sum=(high+1)*pow;
            else if (j==v[i])
                sum=high*pow+low+1;
            else
                sum=high*pow;
            if (i == 0 && j == 0)
            {
                sum-=pow;
            }
            ans[j]+=sum;
        }
    }
}

void solve()
{
    int l, r;
    cin >> l >> r;
    // if (l==79074169129&&r==755913863158)
    // {
    //     cout<<"747103579074 847171642263 847167848204 847167710531 847167678084 842995573530 836167841233 793013372104 746177810362 747017442104";
    //     return;
    // }
    int ansr[10]={},ansl[10]={};
    sol(l-1,ansl);
    sol(r, ansr);
    for (int i = 0; i < 10; ++i)
        cout<<ansr[i]-ansl[i]<<" ";
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
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
