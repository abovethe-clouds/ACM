#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;

ll read()
{
    ll x = 0, w = 1;
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
ll b[22],v[22];
double danjia[21];
void solve()
{
    ll n=read(),k=read(),money=0;
    int s[21]={};
    for (int i = 20; i >=0; i--)
    {
        if (n>=b[i])
        {
            int cnt=n/b[i];
            n-=cnt*b[i];
            s[i]=cnt;
        }
    }
    ll ans=0;
    for (auto x:s)
    {
        ans+=x;
    }
    if (ans>k)
    {
        cout<<-1<<endl;
        return;
    }
    ans=(k-ans)/2;
    for (int i = 20; i >=1; i--)
    {
        while (ans>0&&s[i]>0)
        {
            if (s[i]>ans)
            {
                s[i]-=ans;
                s[i-1]+=ans*3;
                ans=0;
            }
            else
            {
                ans-=s[i];
                s[i-1]+=s[i]*3;
                s[i]=0;
            }
        }
    }
    for (int i = 0;i<21;i++)
        money+=s[i]*v[i];
    cout<<money<<endl;
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
    b[0]=1;
    for (int i = 1; i <= 21; i++)
    {
        b[i] = b[i - 1] * 3;
    }
    v[0]=3;
    for (int i = 1; i < 21; i++)
    {
        v[i]=b[i+1]+i*b[i-1];
    }
    for (int i = 0; i < 21; i++)
    {
        danjia[i]=v[i]*1.0/b[i];
    }
    while (t--)
        solve();
    return 0;
}
