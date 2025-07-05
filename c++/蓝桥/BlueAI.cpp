#include<bits/stdc++.h>
using namespace std;
char a[12][12];
int n,max1=0,ans=0;
void dfs(int x,int y)
{
    
	if (x<0||x>=n||y<0||y>=n)
    {
        return;
    }
    if ((!(x+2<0||x+2>=n||y-2<0||y-2>=n))&&(!(x+1<0||x+1>=n||y-1<0||y-1>=n))&&a[x+1][y-1]=='Q'&&a[x+2][y-2]=='.')
    {   
        ans++;
        if(ans>max1)
            max1=ans;
        a[x+1][y-1]='.' ;
        dfs(x+2,y-2);
        a[x+1][y-1]='Q' ;
        ans--;
    }
    
    if ((!(x+2<0||x+2>=n||y+2<0||y+2>=n))&&(!(x+1<0||x+1>=n||y+1<0||y+1>=n))&&a[x+1][y+1]=='Q'&&a[x+2][y+2]=='.')
    {
        ans++;
        if(ans>max1)
            max1=ans;
        a[x+1][y+1]='.';
        dfs(x+2,y+2);
        a[x+1][y+1]='Q';
        ans--;
    }

    if ((!(x-2<0||x-2>=n||y+2<0||y+2>=n))&&(!(x-1<0||x-1>=n||y+1<0||y+1>=n))&&a[x-1][y+1]=='Q'&&a[x-2][y+2]=='.')
    {
        ans++;
        if(ans>max1)
            max1=ans;
        a[x-1][y+1]='.';
        dfs(x-2,y+2);
        a[x-1][y+1]='Q';
        ans--;
    }

    if ((!(x-2<0||x-2>=n||y-2<0||y-2>=n))&&(!(x-1<0||x-1>=n||y-1<0||y-1>=n))&&a[x-1][y-1]=='Q'&&a[x-2][y-2]=='.')
    {
        ans++;
        if(ans>max1)
            max1=ans;
        a[x-1][y-1]='.';
        dfs(x-2,y-2);
        a[x-1][y-1]='Q';
        ans--;
    }
    return;    
}
int main()
{
    cin>>n;
    for (int i=0;i<n;i++)
    {
		for (int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
	}
	for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 'L')
            {
                
                a[i][j]='.';
                dfs(i, j);
                a[i][j]='L';
            }
        }
    }
    cout<<max1;
    return 0;
}