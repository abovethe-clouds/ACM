#include<bits/stdc++.h>
using namespace std;
struct game
{
	long long start;
	long long over;
	game() {}
	game (long long c,long long d)
	{
		start=c;
		over=d;
	}
};
int shengXu(game x,game y)
{
	return x.over<y.over;
}
game a[1000000];
int main()
{
    int n,ans=1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i].start>>a[i].over;
    	
	}
	sort(a,a+n,shengXu);
	for(int i=1;i<n;i++)
	{
       if(a[i].start>=a[i-1].over) ans++;
       else 
       {
       		a[i].over=a[i-1].over;
       		a[i].start=a[i-1].start;
	   }
    }
    cout<<ans;
    return 0;
}