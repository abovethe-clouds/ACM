#include <bits/stdc++.h>  
using namespace std; 
void solve() 
{  
    string s;
    int ans=0;
    getline(cin,s);
    for(auto &p : s)
    {
        if(p!=' '&&p!='/n')
            ans++;
    }
    cout<<ans;
    return;
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