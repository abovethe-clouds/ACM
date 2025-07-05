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
int tree[1000],winter[1000];
int n;
void dfs(int x)
{
    if(x>=1<<n)
        return;
    else
    {
        dfs(x*2);//左子树
        dfs((x*2)+1);//右子树
        if(tree[2*x]>tree[2*x+1])
        {
            winter[x]=winter[2*x];
            tree[x]=tree[2*x];
        }
        else
        {
            winter[x]=winter[2*x+1];
            tree[x]=tree[2*x+1];
        }
    }
    return;
}
void solve()
{
    cin>>n;
    for (int  i = 0; i < (1<<n); i++)
    {
        cin>>tree[i+(1<<n)];
        winter[i+(1<<n)]=i+1;
    }
    dfs(1);
    cout<<((tree[2]>tree[3])?winter[3]:winter[2]);
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