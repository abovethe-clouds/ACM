#include<bits/stdc++.h>//八皇后
using namespace std;
int ans=0;
int n;
int a[2025][2025];
void print()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if (a[i][j]==-1)
            {
                cout<<j<<" ";
                continue;
            }
        }
    }
}
void fangzhi(int x,int i)
{
    for (int j=1;j<=n;j++)//横向打标记
    {
        a[x][j]++;
    }
    for (int j=1;j<=n;j++)//纵向打标记
    {
        a[j][i]++;
    }
    for (int ceng=1;ceng<=n;ceng++)//↗
    {
        if(x+i-ceng>=1&&x+i-ceng<=n)
            a[ceng][x+i-ceng]++;
    }
    for (int ceng=1;ceng<=n;ceng++)//↘
    {
        if(ceng-x+i>=1&&ceng-x+i<=n)
            a[ceng][ceng-x+i]++;//（x-i）==（cheng-y)
    }
    /*for (int p=1;p<=n;p++)
    {
        for (int q=1;q<=n;q++)
            cout<<a[p][q]<<" ";
        cout<<endl;
    }*/
    a[x][i]=-1;
}
void quxiao(int x,int i)
{
    for (int j=1;j<=n;j++)//横向打标记
    {
        a[x][j]--;
    }
    for (int j=1;j<=n;j++)//纵向打标记
    {
        a[j][i]--;
    }
    for (int ceng=1;ceng<=n;ceng++)//↗
    {
        if(x+i-ceng>=1&&x+i-ceng<=n)
            a[ceng][x+i-ceng]--;
    }
    for (int ceng=1;ceng<=n;ceng++)//↘
    {
        if(ceng-x+i>=1&&ceng-x+i<=n)
            a[ceng][ceng-x+i]--;//（x-i）==（cheng-y)
    }
    a[x][i]=0;
}
void dfs(int x)
{
    for (int i=1;i<=n;i++)
    {
        if (a[x][i]==0)
        {
            if(x==n)
            {
                a[x][i]=-1;
                ans++;
                if (ans<=3)
                {
                    print();
                    cout<<endl;
                    
                }
                a[x][i]=0;
                return;
            }
            fangzhi(x,i);
            dfs(x+1);
            quxiao(x,i);
            
        }
    }
    return;            
}
int main()
{
    cin>>n;
    dfs(1);
    cout<<ans;
    return 0;
}