#include<bits/stdc++.h>
using namespace std;
double work(double a,double b,double c,double d,double x)
{
	double f=a*pow(x,3)+b*pow(x,2)+c*x+d;
	
	return f;
}
int main()
{   
	double l,r,m;
    double a,b,c,d;
    int ans=0;
    cin>>a>>b>>c>>d;
	for(int i=-100;i<100;i++)
	{
		if(work(a,b,c,d,i)==0)
		{
			printf("%d.00 ",i);
			ans++;
			if(ans==3)
				break;
		}
		if(work(a,b,c,d,i)>0&&work(a,b,c,d,i+1)<0)//递减 
		{
			l=i;
			r=i+1;
			for(int j=0;j<10;j++)
			{
				m=l+(r-l)/2;
				if(work(a,b,c,d,m)>0)
				{
					m=(l+r)/2;
					l=m;
				}
				else
				{
					m=(l+r)/2;
					r=m;
				}
			}
			printf("%.2f ",m);
			ans++;
			if(ans==3)
				break;
		}
		if(work(a,b,c,d,i)<0&&work(a,b,c,d,i+1)>0)//递增
		{
			l=i;
			r=i+1;
			for(int j=0;j<10;j++)
			{
				m=l+(r-l)/2;
				if(work(a,b,c,d,m)>0)
				{
					m=(l+r)/2;
					r=m;
				}
				else
				{
					m=(l+r)/2;
					l=m;
				}
			}
			printf("%.2f ",m);
			ans++;
			if(ans==3)
				break;
		}
	}
    return 0;
}