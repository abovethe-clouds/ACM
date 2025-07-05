#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char c;
    cin>>n>>c;
    int h = sqrt((n+1)/2);    
    for (int i=0;i<h;i++)    //上半
    {
        for (int j=0;j<i;j++)//空格 
            cout<<" ";
        for (int j=0;j<2*(h-i)-1;j++)
            cout<<c;
        cout<<endl;
    }
    for (int i=2;i<=h;i++)    //下半
    {
        for (int j=0;j<h-i;j++)
            cout<<" ";
        for (int j=0;j<2*i-1;j++)
            cout<<c;
        cout<<endl;
    }
    cout<<n-2*h*h+1;//补上一个空格 
	return 0;
}