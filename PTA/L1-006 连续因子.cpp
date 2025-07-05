#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0,max=0,begin=0,begin1=0;
    vector<int> a;
    cin>>n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        a.push_back(i);
    }
    int l=a.size();
    for(int i=0;i<l;i++)
    	cout<<a[i]<<" ";
    for(int i=0;i<l-1;i++)
    {
        if(a[i]==a[i+1]-1)
        {
            ans++;
            if(ans>max)
            {
                max=ans;
                begin1=begin;
            }   
        }
        else
        {
            ans=1;
            begin=i;
        }   
    }
    cout<<max<<endl;
    cout<<a[begin1+1];
    for(int i=1;i<max;i++)
        cout<<"*"<<a[begin1+i+1];
    return 0;
}