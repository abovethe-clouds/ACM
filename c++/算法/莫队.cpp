#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn=1e5+5;
int sq,n,m,a[maxn],l=1,r=0,end1[maxn],cnt[maxn],sum[maxn];//end 结果 cnt 出现k次的数的个数 sum 数的个数
struct problem
{
    int l,r,k,i;
}q[maxn];
bool cmp(problem a,problem b)
{
    if(a.l/sq!=b.l/sq)
        return a.l/sq<b.l/sq;
    else
        return a.r<b.r;
}
void add(int x)
{
    cnt[sum[a[x]]]--;//
    sum[a[x]]++;
    cnt[sum[a[x]]]++;
    return;
}
void del(int x)
{
    cnt[sum[a[x]]]--;//
    sum[a[x]]--;
    cnt[sum[a[x]]]++;
    return;
}
void solve()
{
    cin>>n;
    sq=sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        q[i]={l,r,k,i};
    }
    sort(q,q+m,cmp);
    for (int i = 0; i < m; i++)//l,r为[l,r]
    {
        while(q[i].l<l) add(--l);
        while(q[i].r>r) add(++r);
        while(q[i].l>l) del(l++);
        while(q[i].r<r) del(r--);
         
        end1[q[i].i]=cnt[q[i].k];
    }
    for (int i = 0; i < m; i++)
    {
        cout<<end1[i]<<endl;
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