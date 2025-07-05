#include<bits/stdc++.h> 
using namespace std;
bool a[200000];
int main()
{
	// int n,m,j;
	// cin>>n>>m;
	// memset(a,0,sizeof(a));
	// int f=0,t=0,s=0;
	// do
	// {
	// 	++t;
	// 	if(t==n+1) t=1;
	// 	if(a[t]==false) ++s;
	// 	if(s==m)
	// 	{
	// 		s=0;
	// 		j=t;
    //         cout<<j<<" ";
	// 		a[t]=true;
	// 		++f;
	// 	}
	// }while(f!=n);
	// return 0;
	int n,m;
	queue <int> a;
	cin>>n>>m;
	for (int i = 0; i < n; i++)
	{
		a.push(i+1);
	}
	int i=1;
	while (!a.empty())	
	{
		int q=a.front();
		a.pop();
		if(i!=m)
			a.push(q);
		else
		{
			i=0;
			cout<<q<<" ";
		}
			
		i++;
		

	}
	
	
} 
