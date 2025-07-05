#include <bits/stdc++.h>  
using namespace std; 
using i64 = long long;
int a[101];
int shu[101],n;
void solve() 
{  
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>shu[i];
        a[shu[i]]++;
    }
    bool flag=true;
    for (int i = 0; i < n; i++)
    {
        if(a[shu[i]]>=2)
        {
            cout<<shu[i]<<" ";
            a[shu[i]]=0;
            flag=false;
        }
    }
    if(flag)
        cout<<-1;
    
    
    
        
} 
int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    int t = 1; 
    //cin >> t; // T组测试数据，一组时可以注释这行 
    while (t--) 
    { 
        solve();
         
    } 
} 