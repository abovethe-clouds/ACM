#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int N = 1e5, M = N * 2, mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
struct pu
{
    int time,keep,high;
};
int D,G;
vector<pu> hh;
int f[1000];
bool cmp(pu x,pu y)
{
    return x.time<y.time;
}
void solve()
{
    cin>>D>>G;
    pu s;
    s.time=0,s.high=0,s.keep=0;
    hh.push_back(s);
    for (int i = 0; i < G; i++)
    {
        pu a;
        cin>>a.time>>a.keep>>a.high;
        hh.push_back(a);
    }
    sort(hh.begin(),hh.end(),cmp);
    f[0]=10;//
    for (int i = 1; i < G; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            f[j+hh[i].high]=max(f[j+hh[i].high],f[j]-(hh[i].time-hh[i].time));//
        }
    }
    

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
}