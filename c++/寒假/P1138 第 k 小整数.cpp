#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,a[100001]={};
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int o;
        cin>>o;
        a[o]++;
    }
    int ans=0;
    for(int i=1;i<=30000;i++)
    {
        if(a[i]!=0)
        {
            ans++;
            if(ans==k)
            {
                cout<<i;
                return 0;
            }
        }
    }
    cout<<"NO RESULT";
    return 0;
}