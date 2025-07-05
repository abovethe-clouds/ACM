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
ll a[501][501],n,m,k,s[501][501],cnt=0;
void solve()
{
    cin>>n>>m>>k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin>>a[i][j];
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];//前缀和
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int q = i;int p = m;bool flag=false;
            while(p >= j&&q <= n)
            {
                while(q <= n)
                {
                    int sum=s[q][p]-s[q][j-1]-s[i-1][p]+s[i-1][j-1];
                    if(sum<=k)//能过
                    {
                        q++;//右移
                        cnt+=p-j+1;//计算这一列多少元素
                        if(q==n+1)
                            flag=true;
                    }
                    else
                    {
                        p--;//上移
                        break;//上移一层开始查找
                    } 
                      
                }
                if(flag)
                    break;
            }
            
        }
    }
    cout<<cnt;
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