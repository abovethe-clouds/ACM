#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a,sum=0;
    pair<int,int> c[1000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a;
		c[i]=make_pair(a,i+1);
	}
    sort(c,c+n);
    for(int i=0;i<n;i++)
    {
    	cout<<c[i].second<<" ";
	}
	for(int i=0;i<n;i++)
    	sum+=c[i].first*(n-i-1);
    cout<<endl;
    double d=double(sum*1.0)/n;
    printf("%.2f",d);
    return 0;
}