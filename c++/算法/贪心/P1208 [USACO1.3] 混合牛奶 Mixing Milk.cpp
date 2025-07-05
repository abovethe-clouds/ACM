#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,sum=0;
    cin>>n>>m;
    int p,a;
    pair<int,int> c[5000];
    for(int i=0;i<m;i++)
    {
    	cin>>p>>a;
    	c[i]=make_pair(p,a);
	}
	sort(c,c+m);
	int i=0;
	while(n>0)
	{
		
		if(c[i].second<=n)
		{
			n-=c[i].second;
			sum+=c[i].second*c[i].first;
		}
		else
		{
			sum+=n*c[i].first;
			n=0;
			break;
		}
		i++;
	}
	cout<<sum;
    return 0;
}