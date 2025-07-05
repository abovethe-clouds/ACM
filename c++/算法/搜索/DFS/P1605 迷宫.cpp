#include<bits/stdc++.h>
using namespace std;
int N,M,T,sx,sy,fx,fy,lu[5][5],jilu[5][5],ans=0;
void dfs(int x,int y)
{
    if(x>=N||y>=M||x<0||y<0||jilu[x][y]==1||lu[x][y]==1)
        return;
    if(x==fx&&y==fy)
    {
        ans++;
        return;
    }
    int xd[4]={0,1,0,-1},yd[4]={-1,0,1,0};
    
    for (int i = 0; i < 4; i++)
    {   
        jilu[x][y]=1;
        int dx=x+xd[i];
        int dy=y+yd[i];
        dfs(dx,dy);
        jilu[x][y]=0;
        
    }
    
    return;
    
}
/*
2 2 1
1 1 2 2
1 2
*/
int main()
{
    cin>>N>>M>>T>>sx>>sy>>fx>>fy;
    sx--;
    sy--;
    fx--;
    fy--;
    while(T--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        lu[x][y]=1;
        jilu[x][y]=1;
    }
    dfs(sx,sy);
    cout<<ans;
}