#include<bits/stdc++.h>
using namespace std;
int s[5],a[5][21],sum,miin;
int zuonao,younao;
void dfs(int x,int y)
{
    if(y==s[x]+1)
    {
        miin=min(miin,max(zuonao,younao));
        return;
    }
    else
    {
        zuonao+=a[x][y];
        dfs(x,y+1);
        zuonao-=a[x][y];
        younao+=a[x][y];
        dfs(x,y+1);
        younao-=a[x][y];  
    }
    return;
}
int main()
{
    for (int i=1;i<=4;i++)
        cin>>s[i];
    for (int i=1;i<=4;i++)
    {
        for(int j=1;j<=s[i];j++)
        {
            cin>>a[i][j];
        }
        zuonao=0;
        younao=0;
        miin=18000;
        dfs(i,1);
        sum+=miin;        
    }
    cout<<sum;
}