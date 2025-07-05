#include<bits/stdc++.h>
using namespace std;
int xqi,yqi;
int dx[12]={1,-1,2,-2,1,-1,2,-2,2,2,-2,-2},dy[12]={2,2,1,1,-2,-2,-1,-1,-2,2,-2,2};
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
 for (int p = 0; p < 2; p++)
    {
    int tu[20][20]={},jilu[20][20]={};
    memset(jilu,-1,sizeof(jilu));
    cin>>xqi>>yqi;
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
        for (int i = 0; i < 12; i++)
        {
            int x=chu.x+dx[i];
            int y=chu.y+dy[i];
            int step=chu.step+1;
            if(x<21&&y<21&&x>=0&&y>=0&&(tu[x][y]==0))
            {
                zuobiao xin;
                xin.x=x,xin.y=y,xin.step=step;
                duilie.push(xin);
                tu[xin.x][xin.y]=1;//吸取教训
            }
        }
    }
    cout<<jilu[0][0]<<endl;   
}
}
