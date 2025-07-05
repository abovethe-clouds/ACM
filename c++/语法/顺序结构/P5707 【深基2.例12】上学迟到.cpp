#include<bits/stdc++.h>
using namespace std;
int main()
{
    double s,v,h=0;
    cin>>s>>v;
    int t=ceil(s/v);
    t+=10;
    for(int i=1;i<=24;i++)
    {
        if(t>=60)
        {
            t=t-60;
            h+=1;
        }
        else
        break;
    }
    if(t>50)
    {
        if (h>7)
        cout<<24+8-h-1<<":0"<<60-t;
        else
        cout<<"0"<<8-h-1<<":0"<<60-t;
        return 0;
    }
    else
    {
   
    if (h>7)
    cout<<24+8-h-1<<":"<<60-t;
    else
    cout<<"0"<<8-h-1<<":"<<60-t;
    return 0;
    }
}