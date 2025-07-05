#include<bits/stdc++.h>
using namespace std;
int a[19][19];
int n,m,ans=0;
void dfs(int x,int y)
{
    if(x>n||y>m||x<0||y<0)
        return;
    else
    {
        if(x==n&&y==m)
        {
            ans++;
            return;
        }
        else
        dfs(x+1,y+2);
        dfs(x-1,y+2);
        dfs(x-2,y+1);
        dfs(x+2,y+1);
        return;
    }
    
}
int main()
{
    cin>>n>>m;
    dfs(0,0);
    cout<<ans;
}