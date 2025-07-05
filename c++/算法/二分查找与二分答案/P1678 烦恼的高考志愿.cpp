#include<bits/stdc++.h>
using namespace std;
int a[10000000],b[10000000]; 
int main()
{   
	long long n,m,sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	sort(a,a+n);
	for(int i=0;i<m;i++)
	{
		if(b[i]<a[0]||b[i]>a[n-1])
			sum+=min(abs(a[0]-b[i]),abs(a[n-1]-b[i]));
		else
		{
				sum+=min(abs(a[(lower_bound(a,a+n,b[i])-a)]-b[i]),abs(a[(lower_bound(a,a+n,b[i])-a)-1]-b[i]));
		}
		
	}
	cout<<sum;
    return 0;
}