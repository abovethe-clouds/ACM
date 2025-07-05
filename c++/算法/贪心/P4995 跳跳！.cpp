#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,sum=0,p=0,q;
    cin>>n;
    q=n;
    int h[401]={0};
    for(int i=1;i<=n;i++)//输入数据 
    {
    	cin>>h[i];
	}
	sort(h,h+n+1);
	while(q>p)
	{
		sum+=pow((h[q]-h[p]),2);
		p++;
		sum+=pow((h[q]-h[p]),2);
		q--;
	}
	cout<<sum;
	return 0;
}