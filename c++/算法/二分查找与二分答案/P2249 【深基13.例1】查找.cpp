#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int n,m;
int find(int x)
{
	int i=1,j=n,ans=-1;
	while(i<=j)
	{
		int m=i+(j-i)/2;
		if(a[m]<x)
		{
			i=m+1;
		}
		else
		{
			if(a[m]==x)
				ans=m;
			j=m-1;
		}
	}
	return ans; 
}
int main()
{
    cin>>n>>m;
    int o;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=0;i<m;i++)
    {
    	cin>>o;
    	cout<<find(o)<<" ";
	}
    return 0;
}