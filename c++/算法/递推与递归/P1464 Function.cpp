#include<bits/stdc++.h>
using namespace std;
long long e[22][22][22];
int w(long long a,long long b,long long c)
{
	if(a<=0||b<=0||c<=0)
		return 1;
	if(a>20||b>20||c>20)
		return w(20,20,20);
	if(a<b&&b<c) 
		{
			if(e[a][b][c-1]==0)
			{
				 e[a][b][c-1]=w(a,b,c-1);
			}
			if(e[a][b-1][c-1]==0)
			{
				 e[a][b-1][c-1]=w(a,b-1,c-1);
			}
			if(e[a][b-1][c]==0)
			{
				 e[a][b-1][c]=w(a,b-1,c);
			}
			e[a][b][c]=e[a][b][c-1]+e[a][b-1][c-1]-e[a][b-1][c];
		}
	else
		{
			if(e[a-1][b][c]==0)
			{
				 e[a-1][b][c]=w(a-1,b,c);
			}
			if(e[a-1][b-1][c]==0)
			{
				 e[a-1][b-1][c]=w(a-1,b-1,c);
			}
			if(e[a-1][b][c-1]==0)
			{
				 e[a-1][b][c-1]=w(a-1,b,c-1);
			}
			if(e[a-1][b-1][c-1]==0)
			{
				 e[a-1][b-1][c-1]=w(a-1,b-1,c-1);
			}
			e[a][b][c]=e[a-1][b][c]+e[a-1][b-1][c]+e[a-1][b][c-1]-e[a-1][b-1][c-1];
		}
	    return e[a][b][c];
}
int main()
{
    long long a,b,c;
    while(cin>>a>>b>>c)
    {
    	if(a==-1&&b==-1&&c==-1)
    		break;
    	printf("w(%lld, %lld, %lld) = ",a,b,c);
    	cout<<w(a,b,c)<<endl;
	}
    return 0;
}
