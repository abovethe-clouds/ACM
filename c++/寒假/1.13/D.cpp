#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int N = 1e5, M = N * 2, mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
string s;
void change2()
{
    string zero_one ="";
    
    for (int i = 0; i < s.length(); i++)
    {
        int wow;
        if(s[i]>='0'&&s[i]<='9')
        {
            wow=s[i]-'0';
        }
        if(s[i]>='A'&&s[i]<='F')
        {
            wow=s[i]-'A'+10;
        }
        zero_one+=bitset<4>(wow).to_string();
    }
    int l=zero_one.length();
    if(l%3!=0)
    {
        int fc=3-(l%3);
        zero_one+=string(fc,'0')+zero_one;
    }
    string end="";
    for (int i = 0; i < zero_one.length()-1; i+=3)
    {
        end+=to_string((zero_one[i]-'0')*4+(zero_one[i+1]-'0')*2+(zero_one[i+2]-'0')*1);
    }
     while (end.length() > 1 && end[0] == '0') 
     {
        end = end.substr(1);  // 去掉前导零
    }
    cout<<end;
    return;
}
void solve()
{
    cin>>s;
    change2();
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