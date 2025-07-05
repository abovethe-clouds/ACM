#include<bits/stdc++.h>
using namespace std;
int n,k,a[6];
void dfs(int x)
{
    if(x==n)
    {
        for(int i=1;i<=k;i++)
        {
            a[x]=i;
            for(int i=1;i<=n;i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int i=1;i<=k;i++)
    {
        a[x]=i;
        dfs(x+1);
    }
    return;
}
int main()
{
    cin>>n>>k;
    dfs(1);
}