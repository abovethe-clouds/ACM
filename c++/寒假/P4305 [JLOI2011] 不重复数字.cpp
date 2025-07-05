
#include <bits/stdc++.h>  
using namespace std; 
using i64 = long long; 
void solve() 
{  
    set<int> a;
    int n,s;
    cin>>n;
    while(n--)
    {
        cin>>s;
        if(!(a.count(s)))
        {
            cout<<s<<" ";
            a.insert(s);
        }
        
    }
} 
int main() 
{ 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    int t = 1; 
    cin >> t; // T组测试数据，一组时可以注释这行 
    while (t--) 
    { 
        solve();
        cout<<endl; 
    } 
} 