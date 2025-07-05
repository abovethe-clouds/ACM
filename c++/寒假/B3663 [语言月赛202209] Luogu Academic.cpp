#include <bits/stdc++.h>  
using namespace std; 
void solve() 
{  
    int ans=0;
    string a;
    cin>>a;
    int l=a.length();
    if(l<5)
    {
        cout<<0;
        return ;
    }
    for(int i=0;i<l-4;i++)
    {
        if (a[i]=='l'&&a[i+1]=='u'&&a[i+2]=='o'&&a[i+3]=='g'&&a[i+4]=='u')
        ans++;
    }
    cout<<ans;
    return ;
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
    return 0; 
}