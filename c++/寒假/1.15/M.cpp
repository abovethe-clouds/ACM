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
string s;
void solve()
{
    cin>>s;
    for (int i = s.length()-1; i >= 0; i--)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            
            if(s[i]<'X')
            {
                s[i]+=3;
                s[i]=s[i]-'A'+'a';
            }
            else
            {
                s[i]=s[i]+3-26;
                s[i]=s[i]-'A'+'a';
            }
            
        }
        else
        {
            
            if(s[i]<'x')
            {
                s[i]+=3;
                s[i]=s[i]-'a'+'A';
            }
            else
            {
                s[i]=s[i]+3-26;
                s[i]=s[i]-'a'+'A';
            }
            
        }
        cout<<s[i];
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