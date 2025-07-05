#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,h,m;
    cin>>a>>b>>c>>d;
    if(b>d)
    {
        m=60+d-b;
        h=c-a-1;
    }
    else
   {
        m=d-b;
        h=c-a;
    }
    cout<<h<<" "<<m;
    
}