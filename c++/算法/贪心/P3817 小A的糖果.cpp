#include<bits/stdc++.h>
using namespace std;
long long a[100000],sum=0,x;
int main()
{
    int n;
    cin>>n>>x;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
	}
	if(a[0]>x)
	{
		sum+=a[0]-x;
		a[0]=x;
	}
	for(int i=1;i<n;i++)
    {
    	if(a[i-1]+a[i]>x)
    	{
    		sum+=a[i-1]+a[i]-x;
    		a[i]-=a[i-1]+a[i]-x;
		}
	}
	cout<<sum;
    return 0;
}