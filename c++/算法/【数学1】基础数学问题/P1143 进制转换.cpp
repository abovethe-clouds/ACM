#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
int r(char x)
{
    if(x>='0'&&x<='9')
    {
        return int(x-'0');
    }
    else
    {
        return int(x-'A')+10;
    }
}
char fff(int x)
{
    if(x>=0&&x<=9)
        return '0'+x;
    else
        return x-10+'A';
}
void solve()
{
    int b,e,t=0;
    string s;
    cin>>b>>s>>e;
    int l=s.length()-1;
    int j=0;
    for (int i = l; i >= 0; i--)
    {
        t+=pow(b,j++)*r(s[i]);
    }
    stack <char> a;
    while (t!=0)
    {
        int p=t%e;
        t/=e;
        a.push(fff(p));
    }
    while (!a.empty())
    {
        cout<<a.top();
        a.pop();
    }
    
    

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
}