#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int t,sum=0;
        scanf("%d",&t);
        while(t--)
        {
            int a;
            cin>>a;
            sum+=a;
        }
        cout<<sum<<endl;
    }
}