#include<bits/stdc++.h>
using namespace std;
void daoXu(string a)
{
	int i=a.size();
	i-=1;
	for(i;i>=0;i--)
	cout<<a[i];
}
int main()
{
	string a;
	cin>>a;
	daoXu(a);
	return 0;
} 