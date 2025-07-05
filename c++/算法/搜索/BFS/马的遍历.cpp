#include<bits/stdc++.h>
using namespace std;
int tu[400][400],jilu[400][400];

int n,m,xqi,yqi;
int dx[8]={1,-1,2,-2,1,-1,2,-2},dy[8]={2,2,1,1,-2,-2,-1,-1};
struct zuobiao
{
    int x;
    int y;
    int step;
    zuobiao(){}
};
queue<zuobiao> duilie;
int main()
{
    memset(jilu,-1,sizeof(jilu));
    cin>>n>>m>>xqi>>yqi;
    zuobiao qi;
    qi.x=xqi-1;
    qi.y=yqi-1;
    qi.step=0;
    duilie.push(qi);
    while(!(duilie.empty()))
    {
        zuobiao chu=duilie.front();
        tu[chu.x][chu.y]=1;
        jilu[chu.x][chu.y]=chu.step;
        duilie.pop();
        for (int i = 0; i < 8; i++)
        {
            int x=chu.x+dx[i];
            int y=chu.y+dy[i];
            int step=chu.step+1;
            if(x<n&&y<m&&x>=0&&y>=0&&(tu[x][y]==0))
            {
                zuobiao xin;
                xin.x=x,xin.y=y,xin.step=step;
                duilie.push(xin);
                tu[xin.x][xin.y]=1;//吸取教训
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%5d",jilu[i][j]);
        }
        cout<<endl;
    }   
}