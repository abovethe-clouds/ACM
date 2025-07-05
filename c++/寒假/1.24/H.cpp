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
    int x,y;
};

void solve()
{
    int n,m;
    string s;
    cin>>n>>m;
    zuobiao qi;
    for (int i = 0; i < m; i++)
    {
        cin>>s;
        for (int j = 0; j < n; j++)
        {
            if(s[j]=='#')
                tu[i][j]=1;
            else
            {
                if(s[j]=='.')
                    tu[i][j]=0;
                else
                {
                    tu[i][j]=0;
                    qi.x=i;
                    qi.y=j;
                }
            }
        }
    }
    queue <zuobiao> duilie;
    duilie.push(qi);
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
    int cnt=0;
    while(!duilie.empty())
    {
        zuobiao qq=duilie.front();
        cnt++;
        tu[qq.x][qq.y]=1;
        duilie.pop();
        for (int i = 0; i < 4; i++)
        {
            zuobiao ya;
            ya.x=qq.x+dx[i];
            ya.y=qq.y+dy[i];
            if((tu[ya.x][ya.y]==0)&&(ya.x<m)&&(ya.y<n)&&(ya.x>=0)&&(ya.y>=0)&&(jilu[ya.x][ya.y]==0))
            {
                duilie.push(ya);
                tu[ya.x][ya.y]=1;
            }
        }
    }
    cout<<cnt;
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