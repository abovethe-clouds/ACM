#include<bits/stdc++.h>
using namespace std;
int sushu(int n)
{
	int i;
    if (n==0) return 0;
	if (n==1) return 0;
	if (n==2) return 1;
	if (n%2==0) return 0;
	for(i=3;i<n;i+=2)
	{
		if(n%i==0)
			{
				return 0;
				break;
			}
	}
	return 1;
}
int main()
{
    map<char,int> mp;
    int max=-1,min=999;
    string s;
    cin>>s;
    for(auto &e:s)
    {
        if(!mp.count(e))
            mp[e]=1;
        else
            mp[e]++;
    }
    for (auto& [key, value] : mp) 
    {
        if(value>max) max=value;
        if(value<min) min=value;
    }
    if(sushu(max-min))
        cout<<"Lucky Word"<<endl<<max-min;
    else
        cout<<"No Answer"<<endl<<0;

}