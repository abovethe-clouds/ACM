//https://www.lanqiao.cn/problems/20086/learning/?contest_id=228
#include<bits/stdc++.h>
using namespace std;
int wait[100000], o=0,yinshu[100000],judge[100000000];
void zhishushai(long long n)//质数用0表示
{   
     for(unsigned int i=2;i<=sqrt(n);)
    {
        for(unsigned int j=2;j<=(n/i);j++)
        {
            wait[i*j]=1;
        }
        i++;
        while(wait[i]!=0)
        {
            i++;
        }
    }
    wait[1]=1;
}
void zhiyinshu(long long x)
{
    for(int i=2;i<=sqrt(x);i++)
    {
        if(wait[i]==0&&x%i!=0)
        {
            wait[i]=1;
        }
    }
    for(int i=2;i<=sqrt(x);i++)
    {
        if(wait[i]==0)
        {
            yinshu[o]=i;
            o++;
        }
    }
}
int main()
{
    long long n,sum,ans=1;
    cin>>n;
    sum=n;
    zhishushai(n);
    zhiyinshu(n);
    for(int i=0;i<o;i++)
    {
        for(int j=1;j<=n/yinshu[i];j++)
            judge[yinshu[i]*j]=1;
    }
    for(int j=1;j<=n;j++)
    {
        if(judge[j]==0)
            ans++;
    }
    cout<<ans-1;
}