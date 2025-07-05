#include<bits/stdc++.h>
using namespace std; 
long long length[100000];
int sum(int x,double l)
{
	int sum=0;
	if (l>=-1&&l<0.5)
		return -1;
	for(int i=0;i<x;i++)
	{
		sum+=int(length[i]/l);
	}
	return sum;		
}
int main()
{   
	int  n,k;
	double p=0,q=0,o;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
	    cin>>length[i];
	    if(q<length[i])
	    	q=length[i];
	}
	for(int i=1;i<=2000;i++)	
	{
		o=p+(q-p)/2;
		if(sum(n,o)==-1)
		{
			cout<<0;
		    return 0;
		}	
		if(sum(n,o)<k) //太长了
		{
			q=o;
		}
		else
		{
			p=o;
		}
	}
	cout<<int(o);
    return 0;
}