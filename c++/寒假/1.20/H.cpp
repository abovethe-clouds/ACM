#include<bits/stdc++.h>
using namespace std;
int tu[400][400],jilu[400][400];
int max1=0;
int n,m,xqi,yqi;
int dx[8]={1,1,1,0,0,-1,-1,-1},dy[8]={1,0,-1,1,-1,1,0,-1};
void print()
{
    cout<<endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%5d",jilu[i][j]);
        }
        cout<<endl;
    }
    return;
}
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
    qi.x=n-xqi;
    qi.y=yqi-1;
    qi.step=0;
    duilie.push(qi);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char a;
            cin>>a;
            if(a=='.')
            {
                jilu[i][j]=0;
                tu[i][j]=0;
            }
            else
            {
                jilu[i][j]=1;
                tu[i][j]=1;
            }
        }
    }
    jilu[qi.x][qi.y]=1;
    while(!(duilie.empty()))
    {
        zuobiao chu=duilie.front();
        tu[chu.x][chu.y]=1;
        jilu[chu.x][chu.y]=chu.step;
        max1=max1>chu.step?max1:chu.step;
        duilie.pop();
        //print();
        for (int i = 0; i < 8; i++)
        {
            int x=chu.x+dx[i];
            int y=chu.y+dy[i];
            int step=chu.step+1;
            if(x<m&&y<n&&x>=0&&y>=0&&(tu[x][y]==0))
            {
                zuobiao xin;
                xin.x=x,xin.y=y,xin.step=step;
                duilie.push(xin);
                max1=max1>step?max1:step;
                tu[xin.x][xin.y]=1;//吸取教训
                jilu[xin.x][xin.y]=step;
            }
        }
    }
    cout<<max1-1;
}