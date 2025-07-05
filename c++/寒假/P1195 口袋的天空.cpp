#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int  mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
int n,m,tu[5001][5001],changdu[5001],k;
bool jilu[5001];
bool jianshu()
{
    memset(changdu,inf,sizeof(changdu));
    changdu[1]=0;
    int sss=n;
    int cishu=0;
    while(sss--)
    {
        int min1=inf;
        int dian=-1;
        for (int i = 1; i <= n; i++)
        {
            if(changdu[i]<=min1&&jilu[i]==false)
            {
                min1=changdu[i];
                dian=i;
            }   
        }
        jilu[dian]=true;    //固定点，加入树
        cishu++;
        if(cishu==k)
            return 0;
        for(int i=1;i<=n;i++)
        {
            if(jilu[i]==false)
            {
                changdu[i]=min(changdu[i],tu[dian][i]);
            }
        }                   //更新点到树的距离
        
    }
    return 1;
}
void solve()
{
    memset(tu,inf,sizeof(tu));
    cin>>n>>m>>k;
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        tu[a][b]=min(tu[a][b],c);
        tu[b][a]=min(tu[a][b],c);
    }
    for (int i = 1; i <= n; i++)
    {
        tu[i][i]=0;
    }
    if(jianshu())
    {
        
        {
            cout<<"No Answer";
            return;
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(jilu[i])
        sum+=changdu[i];
    }
    cout<<sum;
    return;
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