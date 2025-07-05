#include<bits/stdc++.h>
using namespace std;
int a[5001][5000];
int main()
{
    int p,q,len=1;
    cin>>p>>q;
    int n=q-p+1;
    a[1][1]=1;
    a[2][1]=1;
    if(n<=2)
    	cout<<a[n][1];
    else
    {
    	for(int i=3;i<=n;i++)   
    	{
    		for(int j=1;j<=len;j++)
			{
				a[i][j]+=a[i-1][j]+a[i-2][j];
				if(a[i][j]>=10)
				{
					 a[i][j+1]+=a[i][j]/10;
					 a[i][j]%=10;
				}
			}
			if(a[i][len+1]>0)
				{
				    len++;
				}		
		}
		bool flag=false;
		for(int i=len;i>=1;i--)
		{
			if(a[n][i]!=0)
			{
				cout<<a[n][i];
				flag=true;
			}
			else
			if(flag==true)
				cout<<a[n][i];
		}
	}
    return 0;
}