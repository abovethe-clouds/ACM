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
    int a;
    while (cin>>a)
    {
        if(a==0)
            return;
        else
        {
            int sum=0;
            while(a>1)
            {
                sum+=a/3;
                a=a/3+a%3;
                if(a==2)
                {
                    sum++;
                    break;
                }
            }
            cout<<sum<<endl;
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