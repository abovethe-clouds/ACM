#include<bits/stdc++.h> //高精度 dfs
using namespace std;
string s;
int a[40],change[10],n,l,ans;
void fenLi(string x) //分离数字
{
    l=x.length();
    for(int i=0;i<l;i++)
        a[i]=int(x[i]-'0');
    return;
}
void dfs(int x)
{
    if(x==l)
    {
        ans++;
        return;
    }
    else
    {
        for(int i=0;i<=9;i++)
        {
            if(a[x]==i&&change[i]!=-1)
            {
                
                int o=a[x];
                a[x]=change[i];
                
                dfs(x+1);
                a[x]=o;
            }
        }
        dfs(x+1);
        return;
    }
}
int main()
{
    cin>>s;
    fenLi(s);
    cin>>n;
    memset(change,-1,sizeof(change));
    for(int i=0;i<n;i++)
    {
        int o;
        cin>>o>>change[o];
    }
    dfs(0);
    cout<<ans+1;
}