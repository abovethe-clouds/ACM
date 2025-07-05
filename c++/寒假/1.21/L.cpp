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

void solve()
{
    string s;
    cin>>s;
    int l=s.length();
    char ch;
    for (int i = 0; i < l; i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            int a=s[i]-'0';
            while(a--)
                cout<<ch;
        }
        else
        {
            ch=s[i];
            cout<<ch;
        }    
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t --)
        solve();

    return 0;
}