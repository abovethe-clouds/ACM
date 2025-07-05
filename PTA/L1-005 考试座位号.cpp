#include<bits/stdc++.h>
using namespace std;
struct student
{
    string ID;
    int shi,kao;
    student() {}
 }a[1000];
int main()
{    
    int n,m,u;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>a[i].ID>>a[i].shi>>a[i].kao;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
    {
    	cin>>u;
		for(int j=0;j<n;j++)
    	{
    		if(u==a[j].shi)
    		{
    			cout<<a[j].ID<<" "<<a[j].kao<<endl;
    			break;
			}
		}
	}
}