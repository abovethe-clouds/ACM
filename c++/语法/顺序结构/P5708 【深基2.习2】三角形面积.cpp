#include<bits/stdc++.h>
using namespace std;

int main()
{
	double a,b,c,S,p;
	cin>>a>>b>>c;
	p=(a+b+c)/2;
	S=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.1lf",S);
	return 0;
} 