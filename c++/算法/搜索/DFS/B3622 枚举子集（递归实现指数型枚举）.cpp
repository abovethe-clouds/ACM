#include<bits/stdc++.h>
using namespace std;
int n,a[11];
void print()
{
    for (int i = 1; i <= n; i++)
        {
            if(a[i])
            {
                cout<<"Y";
            }
            else
                cout<<"N";
        }
    cout<<endl;
}
void dfs(int x)
{
    if (x==n)
    {
        print();
        a[x]=1;
        print();
        a[x]=0;
        
    }
    else
    {
        dfs(x+1);
        a[x]=1;
        dfs(x+1);
        a[x]=0;
    }
    
}
int main()
{
    cin>>n;
    dfs(1);
}