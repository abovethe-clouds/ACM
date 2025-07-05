#include <bits/stdc++.h>  
using namespace std;
map<pair<string,string>,int> mp;
void cun(string x,string y,int t)
{
    if(t==0)
    mp[{x,y}]=0;
    else
    mp[{x,y}]+=t;
    return;
}
void cha(string x,string y)
{
    cout<<mp[{x,y}]<<endl;
} 
void solve() 
{  
    int a,b;
    cin>>a>>b;
    while(b--)
    {
        int judge;
        cin>>judge;
        if(judge==1)
        {
            string x,y;int t;
            cin>>x>>y>>t;
            cun(x,y,t);
        }
        else
        {
            string x,y;
            cin>>x>>y;
            cha(x,y);
        }
    }

} 
int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    int t = 1; 
    //cin >> t; 
    while (t--) 
    { 
        solve(); 
    } 
}