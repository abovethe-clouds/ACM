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
bool judge(int n)
{
    int sum=0,ans=n;
    while(n)
    {
        int a=n%10;
        sum=sum*10+a;
        n/=10;
    }
    if(sum==ans)
        return true;
    else
        return false;
}
void solve()
{
    int max1=0;
    for (int i = 100; i < 1000; i++)
    {
        for (int j = 100; j < 1000; j++)
        {
            int ya=i*j;
            if(judge(ya))
                max1=max(max1,ya);
        }
        
    }
    cout<<max1;
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