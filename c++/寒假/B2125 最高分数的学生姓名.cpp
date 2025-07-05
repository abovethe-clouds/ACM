#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=0,max1=0,a;
    string s,b;
    cin>>n;
    while(n--)
    {
        cin>>a;
        if(a>max1)
        {
            cin>>s;
            max1=a;
        }
        else 
            cin>>b;
    }
    cout<<s; 
    return 0;
}