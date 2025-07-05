#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x[200000],n,t=0;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin>>a;
        switch (a)
        {
        case 0:
            long long o;
            cin>>o;
            t++;
            x[t]=max(o,x[t-1]);
            
            break;
        case 1:
            if(t!=0)
            t--;
            break;
        default:
            if(t!=0)
            cout<<x[t]<<endl;
            else
            cout<<0<<endl;
            break;
        }
    }
}