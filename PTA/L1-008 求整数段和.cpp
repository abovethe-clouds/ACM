#include<bits/stdc++.h>
using namespace std;
int main()
{
    int begin,last,sum=0,o=0;
    cin>>begin>>last;
    for(int i=begin;i<=last;i++)
    {
        o++;
        sum+=i;
        printf("%5d",i);
        if(o==5)
        {
            o=0;
            cout<<endl;
        }
            
    }
    if(o==0)
    cout<<"Sum = "<<sum;
    else
    cout<<endl<<"Sum = "<<sum;
}