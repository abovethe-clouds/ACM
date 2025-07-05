#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> v;
    string s;
    int x;
    cin>>s>>x;
    int l=s.length();
    if(x>=l)
    cout<<0;
    else
    {
	
    for(int i=0;i<l;i++)
    	v.push_back(int(s[i]-'0'));
    for(int i=x;i>0;i--)
    {
    	bool flag=false;
		for(int j=0;j<v.size()-1;j++)
		{
			if(v[j]>v[j+1])
			{
				v.erase(v.begin()+j);
				flag=true;
				break;
			}
		}
		if (flag==false)
		{
			v.erase(v.end()-1);
		}
	}
	bool flag=false;
	if(v.size()==1)
	   	cout<<v[0];
	else
	{
	
	for(int i=0;i<v.size();i++)
	{
		if(v[i]!=0)
		{     
			cout<<v[i];
			flag=1;
		}
		else
		{
			if(flag==1)
				cout<<v[i];
	
		}  
	}
	} 
	}
    return 0;
}
