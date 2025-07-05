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
char mp[301][301];
int read() 
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') 
    {  
        if (ch == '-') w = -1;        
        ch = getchar();               
    }
    while (ch >= '0' && ch <= '9') 
    {  
        x = x * 10 + (ch - '0');
        ch = getchar();  
    }
    return x * w; 
}
bool vis[301][301];
int portal[26][5];
struct point
{
    int x,y,step;
};
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void solve()
{
    int xb,yb,xe,ye;
    point b;
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        for (int j = 0; j < s.length(); j++)
        {
            mp[i][j]=s[j];
            if(mp[i][j]>='A'&&mp[i][j]<='Z')
            {
                int idx=mp[i][j]-'A';
                if(!portal[idx][4])
                {
                    portal[idx][0]=i;
                    portal[idx][1]=j;
                    portal[idx][4]=1;
                }
                else if(portal[idx][4]==1)
                {
                    portal[idx][2]=i;
                    portal[idx][3]=j;
                    portal[idx][4]=2;
                }
            }
            else if(mp[i][j]=='#')
                vis[i][j]=1;
            else if(mp[i][j]=='@')
                b.x=i,b.y=j,b.step=0;
            else if(mp[i][j]=='=')
                xe=i,ye=j;
        }
    }
    /* 
    for (int i = 0; i < 26; i++)
    {
        cout<<char('A'+i)<<" ";
        for (int j = 0; j < 4; j++)
        {
            cout<<portal[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    queue<point> q;
    q.push(b);
    while (!q.empty())
    {
        int x=q.front().x;
        int y=q.front().y;
        int step=q.front().step+1;
        //vis[x][y]=1;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xn=x+dx[i];
            int yn=y+dy[i];
            if(mp[xn][yn]>='A'&&mp[xn][yn]<='Z'&&!vis[xn][yn]&&xn>=0&&xn<n&&yn>=0&&yn<m&&portal[mp[xn][yn]-'A'][4]==2)
            {
                int idx=mp[xn][yn]-'A';
                //cout<<xn+1<<" "<<yn+1<<endl;
                //vis[xn][yn]=1;
                if(portal[mp[xn][yn]-'A'][2]==xn&&portal[mp[xn][yn]-'A'][3]==yn)
                {
                    xn=portal[idx][0];
                    yn=portal[idx][1];
                    //cout<<1<<" "<<xn+1<<" "<<yn+1<<endl;
                    //vis[xn][yn]=1;
                }
                else
                {
                    xn=portal[idx][2];
                    yn=portal[idx][3];
                    //cout<<2<<" "<<xn+1<<" "<<yn+1<<endl;
                    //vis[xn][yn]=1;
                }
                point oo;
                oo.x=xn;
                oo.y=yn;
                oo.step=step;
                
                q.push(oo);
                if(oo.x==xe&&oo.y==ye)
                {
                    cout<<step;
                    return;
                }
            }
            else if(!vis[xn][yn]&&xn>=0&&xn<n&&yn>=0&&yn<m)
            {
                //cout<<xn+1<<" "<<yn+1<<endl;
                vis[xn][yn]=1;
                point oo;
                oo.x=xn; 
                oo.y=yn;
                oo.step=step;
                q.push(oo);
                if(oo.x==xe&&oo.y==ye)
                {
                    cout<<step;
                    return;
                }
            }
        }
    }
    cout<<-1;
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