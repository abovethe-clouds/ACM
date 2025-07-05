#include<bits/stdc++.h>
using namespace std;
int n,k,a[11],b[11];
void dfs(int x)
{
    if(x==k)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                a[i]=1;
                b[x]=i;
                for(int i=1;i<=k;i++)
                {
                    cout<<b[i]<<" ";
                }
                cout<<endl;
                a[i]=0;
            }    
        }
    }
    else
    {
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            a[i]=1;
            b[x]=i;
            dfs(x+1);
            a[i]=0;
        }    
    }
    }
}
int main()
{
    cin>>n>>k;
    dfs(1);
}