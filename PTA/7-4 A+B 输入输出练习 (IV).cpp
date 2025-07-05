#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin>>n)
    {
        if(n==0)
            return 0;
        int sum=0;
        for (int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            sum+=a;
        }
        cout<<sum<<endl;
    }
    
}