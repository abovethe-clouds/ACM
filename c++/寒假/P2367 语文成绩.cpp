#include <bits/stdc++.h>  
using namespace std;
int m,n,great[5000001],cha[5000001],min1=1000; 
void solve() 
{  
    cin>>m>>n;
    for (int i = 1; i <= m; i++)
    {
        cin>>great[i];
        cha[i]=great[i]-great[i-1];
    }
    for (int i = 1; i <= n; i++)
    {
        int l,r,fen;
        cin>>l>>r>>fen;
        cha[l]+=fen;
        cha[r+1]-=fen;
    }
    for (int i = 1; i <= m; i++)
    {
        great[i]=great[i-1]+cha[i];
        min1=min(great[i],min1);
    }
    cout<<min1;
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