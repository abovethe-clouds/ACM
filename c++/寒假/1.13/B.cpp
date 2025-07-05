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
int m[1001][1001],n,x[1001],y[1001],xx1,yy1;
void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
void chuizhi(int x,int y)
{
    if(m[x][y]==0)
        return;
    if(x>0)
    {
        int s=m[x][y];
        if (m[x-1][y]!=0)
        {
            for (size_t i = 0; i < n; i++)
            {
                m[i][y]-=s;
            }
        }
        
    }
    else
    {
        int s=m[x][y];
        if (m[x+1][y]!=0)
        {
            for (size_t i = 0; i < n; i++)
            {
                m[i][y]-=s;
            }
        }
    }
    //print();
    //cout<<endl;
    return;
}
void shuiping(int x,int y)
{
    if(m[x][y]==0)
        return;
    if(y>0)
    {
        int s=m[x][y];
        if (m[x][y-1]!=0)
        {
            for (size_t i = 0; i < n; i++)
            {
                m[x][i]-=s;
            }
        }
    }
    else
    {
        int s=m[x][y];
        if (m[x][y+1]!=0)
        {
            for (size_t i = 0; i < n; i++)
            {
                m[x][i]-=s;
            }
        }
    }
    //print();
    //cout<<endl;
    return;
}
void solve()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>m[i][j];
            if(m[i][j]==-1)
            {
                xx1=i;
                yy1=j;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if(m[i][j]!=0&&m[i][j]!=-1)
            {
                shuiping(i,j);
                chuizhi(i,j);
            }
        }
    }
    cout<<0-m[xx1][yy1]-1;
    
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