#include <bits/stdc++.h>  
using namespace std; 
int a[100001],s[100001],n,m;
void solve() 
{  
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=a[i]+s[i-1];
    }
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        int l,r;
        cin>>l>>r;
        cout<<s[r]-s[l-1]<<endl;
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