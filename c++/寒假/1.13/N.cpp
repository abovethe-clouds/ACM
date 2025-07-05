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
void solve()
{
    cin>>s;
    for (int i = 0; i < s.length(); i++)
    {
        switch (s[i])
        {
        case 'A':
            cout<<'T';
            break;
        
        case 'T':
            cout<<'A';
            break;
        case 'C':
            cout<<'G';
            break;
        case 'G':
            cout<<'C';
            break;
        }
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