#include <bits/stdc++.h>  
using namespace std; 
#define ull unsigned long long
int tencifang(ull x)
{
    int cnt=0;
    while(x!=0)
    {
        x/=10;
        cnt++;
    }
    return cnt;
}
int tou(ull x)
{
    while(!(x<10&&x>0))
    {
        x/=10;
    }
    return x;
}
void solve() 
{  
    string a,b;
    cin>>a>>b;
    int l1=a.length();
    int l2=b.length();
    ull a1=1,a2=1;
    for(int i=l1-1;i>=0;i--)
    {
        if(a[i]>a[0])
            a1*=(a[0]-'0');
        else 
            a1*=(a[i]-'0');
    }
    for(int i=l2-1;i>=0;i--)
    {
        if(b[i]>b[0])
            a2*=(b[0]-'0');
        else 
            a2*=(b[i]-'0');
    }
    cout<<a1-a2;
    
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