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
ll a[101],n,sum,min1=inf,co;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    int zuo=0;
    for (int i = 1; i < n; i++)
    {
        int you=(sum-zuo);
        if(min1>abs(you-zuo))
        {
            min1=abs(you-zuo);
            co=i;
        }
        zuo+=a[i];
    }
    cout<<co;   
    return 0;
}