#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
bitset<1000010> bt;
int prime[100010],cnt;
int cishu[100000];
void euler(int n)//欧拉筛
{
    bt.set();
    for(int i=2;i<=n;i++)
    {
        if(bt[i]) prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<=n;j++)
        {
            bt[i*prime[j]]=0;
            if(i%prime[j]==0) break;
        }
    }
}
const int N = 1e5, M = N * 2, mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
void fenjie(int x)
{
	int i=1;
	while (x!=1)
    {
        
        while (x%prime[i]==0)
        {
            x/=prime[i];
            cishu[i]++;
        }
        i++;
    }
    return;
}

void solve()
{
    int n;
    cin>>n;
    euler(n);
    for(int i=2;i<=n;i++)
    {
        fenjie(i);
    }
    for(int i=1;i<=cnt;i++)
    {
        if(cishu[i]!=0)
        {
            cout<<prime[i]<<" "<<cishu[i]<<endl;
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