#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long x,y;
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        if(x==y)
            cout<<0<<endl;
        else
        {
            if(x%y==0||y%x==0)
                cout<<max(x,y)<<endl;
            else
                cout<<x+y<<endl;
        }
    }
    return 0;
}