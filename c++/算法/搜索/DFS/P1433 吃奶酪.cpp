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
int n;
double min1=1e18;
pair<double,double> a[15];
bool mp[15];
double add(double x1,double y1,double x2,double y2)
{
    double sum=sqrt(pow((x1-x2),2)+pow((y1-y2),2));
    return sum;
}
void dfs(int p,int cnt,double x,double y,double sum)//下一个点，第几个，前驱坐标，路径
{
    mp[p]=1;
    double x1=a[p].fir,y1=a[p].sec;
    sum+=add(x1,y1,x,y);
    if(cnt==n)
    {
        min1=min(min1,sum);
        mp[p]=0;
        return;
    }
    if(sum>=min1)
    {
        mp[p]=0;
        return;
    }   
    for (int i = 0; i < n; i++)
    {
        if(!mp[i])
            dfs(i,cnt+1,x1,y1,sum);
    }
    mp[p]=0;
    return;
}
void solve()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        double x,y;
        cin>>x>>y;
        a[i]=make_pair(x,y);
    }
    if (n == 0) 
    { 
        printf("0.00\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        dfs(i,1,0,0,0);
    }
    printf("%.2f",min1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        freopen("test.in", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
}