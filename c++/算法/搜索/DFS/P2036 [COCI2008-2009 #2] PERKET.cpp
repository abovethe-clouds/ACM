#include<iostream>
using namespace std;
int n,s[10],b[10],min1=9999999,ku=0,suan=1;
void dfs(int x)
{
    if (x==n)
    {
        if(abs(ku-suan)<min1&&!(ku==0&&suan==1))
            min1=abs(ku-suan);
        return;
    }
    else
    {
        dfs(x+1);
        suan*=s[x];
        ku+=b[x];
        dfs(x+1);
        suan/=s[x];
        ku-=b[x];
        return;
    }
}
int main()
{
	cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i]>>b[i];
    dfs(0);
    cout<<min1;
} 
