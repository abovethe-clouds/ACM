#include<bits/stdc++.h>
using namespace std;
int main()
{
    double h,r,v;
    cin>>h>>r;
    v=r*r*3.14*h/1000;
    int t=ceil(20/v);
    cout<<t;
    
}