#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
int mp[3001][3001],dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
bool judge[3001][3001],end1[3001][3001];
struct point//点 
{
    int t;
    int x,y;
    bool operator> (const point &a) const
    {
        return t>a.t;
    }    
};
priority_queue<point,vector<point>,greater<point>> down_point; 
queue<point> visit;
void disaster(int x,int y)//破坏函数
{
    judge[x][y]=1;
    if(x>0)
        judge[x-1][y]=1;
    judge[x+1][y]=1;
    if(y>0)
        judge[x][y-1]=1;
    judge[x][y+1]=1;
}
void dis(int t) //把当前时间的陨石落下
{
    while(!down_point.empty() && down_point.top().t <= t)
    {
    	point p=down_point.top();
    	down_point.pop();
    	disaster(p.x,p.y);
	}
}
void solve()
{
    int m;
    cin>>m;
    for (int i = 0; i < m; i++)//输入点，然后终点图计算
    {
        point p;
        cin>>p.x>>p.y>>p.t;
        int x=p.x,y=p.y;
        end1[x][y]=1;
        if(x>0)
            end1[x-1][y]=1;
        end1[x+1][y]=1;
        if(y>0)
            end1[x][y-1]=1;
        end1[x][y+1]=1;
        down_point.push(p);
    }
    point p;
    p.x=0,p.y=0,p.t=1;
    visit.push(p);
    while (!visit.empty())
    {
        point p=visit.front();
        visit.pop();
        int x=p.x,y=p.y,t=p.t;
        dis(t);
        judge[x][y]=1;
        if(end1[x][y]==0)
        {
            cout<<t-1;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int x1=x+dx[i],y1=y+dy[i];
            if(x1>=0&&y1>=0&&judge[x1][y1]==0)
            {
                point pp;
                pp.x=x1,pp.y=y1,pp.t=t+1;
                judge[x1][y1]=1;
                visit.push(pp);
            }
        }
        
    }
    cout<<-1;
    return;
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
}