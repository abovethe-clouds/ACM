#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
int tu[1001][1001],jilu[1001][1001];
struct zuobiao
{
    int x,y,step;
};

void solve()
{
    int n,zhongx,zhongy;
    string s;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>s;
        for (int j = 0; j < n; j++)
        {
            tu[i][j]=int(s[j]-'0');
        }
    }
    zuobiao qi;
    cin>>qi.x>>qi.y>>zhongx>>zhongy;
    qi.x--;
    qi.y--;
    zhongx--;
    zhongy--;
    qi.step=0;
    queue <zuobiao> duilie;
    duilie.push(qi);
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    while(!duilie.empty())
    {
        zuobiao qq=duilie.front();
        tu[qq.x][qq.y]=1;
        jilu[qq.x][qq.y]=qq.step;
        duilie.pop();
        for (int i = 0; i < 4; i++)
        {
            zuobiao ya;
            ya.x=qq.x+dx[i];
            ya.y=qq.y+dy[i];
            ya.step=qq.step+1;
            if((tu[ya.x][ya.y]==0)&&(ya.x<n)&&(ya.y<n)&&(ya.x>=0)&&(ya.y>=0)&&(jilu[ya.x][ya.y]==0))
            {
                duilie.push(ya);
                tu[ya.x][ya.y]=1;
            }
        }
    }
    cout<<jilu[zhongx][zhongy];
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