#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b;
    cin>>n;
    int cha[1000];
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        cha[i-1]=abs(a-b);
        swap(a,b);
    }
    for(int i=1;i<n;i++)
    {
        if (!(cha[i]<=n-1&&cha[i]>=1))
        {
            cout<<"Not jolly";
            return 0;
        }    
    }
    cout<<"Jolly";
    return 0;
}