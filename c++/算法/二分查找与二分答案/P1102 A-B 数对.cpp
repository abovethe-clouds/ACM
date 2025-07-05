#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,ans=0;
	cin>>n>>m;
    long long a[200000]={0};
    for(long long i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
    {
    	int c=m+a[i];
		int q=lower_bound(a+1,a+n+1,c)-a;
		int p=upper_bound(a+1,a+n+1,c)-a; //笑，偷大懒
		ans+=(p-q);
	}
	cout<<ans;
    return 0;
}