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
int a[50],n,k,sum=0,cnt;
void dfs(int x,int z)
{
    if(x==n)
    {
        if(sum*1.0/z==k)
            cnt++;
        return;
    }
    else
    {
        dfs(x+1,z);
        sum+=a[x];
        dfs(x+1,z+1);
        sum-=a[x];
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    dfs(0,0);
    cout<<cnt;
    return 0;
}