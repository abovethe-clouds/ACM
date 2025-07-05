#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0;
    int a[10000];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
        {
            if (a[j]<a[i])
            {
                swap(a[j],a[i]);
                ans++;
            }    
        }
    cout<<ans;
}