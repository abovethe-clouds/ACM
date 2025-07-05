#include <bits/stdc++.h>  
using namespace std; 
int cishu(int x)
{
    int cnt=0;
    for(int i=1;i<=9;i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if(x==i*j)
                cnt++;
        }
    }
    return cnt;
}
void solve() 
{  
    int x;
    cin>>x;
    cout<<2025-cishu(x)*x;

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