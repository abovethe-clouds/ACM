#include<bits/stdc++.h>
using namespace std;
int n,k,a[21],b[21],sum,ans;
int judge(int x)
{
    if(x==2) return 1;
    if(x==1) return 0;
    int flag=1;
    for(int i=2;i*i<=x;i++)
    {
        if (x%i==0)
        {
            flag=0;
            break;
        }
    }
    return flag;
}
void dfs(int x,int y)
{
    if (x==k+1)
    {
        if(judge(sum))
            ans++;
        return;
    }
    else
    {
        for(int i=y+1;i<=n;i++)
        {
            if(b[i]==0)
            {
                sum+=a[i];
                b[i]=1;
                dfs(x+1,i);
                sum-=a[i];
                b[i]=0;
            }
        }
        return;
    }

}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,0);
    cout<<ans;
}