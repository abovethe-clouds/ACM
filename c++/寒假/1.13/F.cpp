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
ll sum=0;
bool judge(int x)
{
    while(x!=0)
    {
        int a;
        a=x%10;
        if(a==2||a==0||a==1||a==9)
            return true;
        x/=10;
    }
    return false;
}
void solve()
{
    for (int i = 1; i <= 2019; i++)
    {
        if(judge(i))
            sum+=i;
    }
    cout<<sum;
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