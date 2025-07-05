#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,cnt=0;
    int judge[1001]={};
    cin>>m>>n;
    queue<int> a;
    for(int i=0;i<n;i++)
    {
        int o;
        cin>>o;
        if (judge[o]==0)
        {
            int u=a.size();
            if(m==u)
            {
                int l=a.front();
                judge[l]=0;
                a.pop();
                a.push(o);
                judge[o]=1;
                cnt++;
            }
            else
            {
                a.push(o);
                judge[o]=1;
                cnt++;
            }
        }
    }
    cout<<cnt;
}