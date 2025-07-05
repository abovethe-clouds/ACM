#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,y,sum=0;
    cin>>x>>y;
    vector<vector<int>> a(x, vector<int>(y));
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
            cin>>a[i][j];
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
        {
            if (i==0||j==0||i==x-1||j==y-1)
            sum+=a[i][j];
        }
    cout<<sum;
}