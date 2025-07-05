#include<bits/stdc++.h> 
using namespace std;
int shengxu(pair<int,int> a,pair<int,int> b)
{
	return a.second<b.second;
}
int main()
{
	int n,a,s,b,ans=0;
	cin>>n>>s>>a>>b;
	pair<int,int> c[n];
	for(int i=0;i<n;i++)
	{
		int p,q;
		cin>>p>>q;
		c[i]=make_pair(p,q);
	}
	sort(c,c+n,shengxu);
	for(int i=0;i<n&&s>=0;i++)
	{
		if(c[i].first<=(a+b)&&s>=c[i].second)
		{
			ans++;
			s-=c[i].second;
		}
	}
	cout<<ans;
	return 0;
} 