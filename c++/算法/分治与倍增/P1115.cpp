// #include<bits/stdc++.h>
// using namespace std;
// #define fir first
// #define sec second
// #define endl "\n"   
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<int,int> pii;
// typedef pair<ll, ll> pll;
// const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=2e5+5;
// int a[maxn],n;
// int mid(int m,int l,int r)//[l,r]
// {
//     int max1=-inf,max2=-inf,sum1=0,sum2=0;
//     for(int i=m;i>=l;i--)
//     {
//         sum1+=a[i];
//         max1=max1>sum1?max1:sum1;
//     }
//     for(int i=m+1;i<=r;i++)
//     {
//         sum2+=a[i];
//         max2=max2>sum2?max2:sum2;
//     }
//     return max1+max2;
// }
// int push_down(int l,int r)
// {
//     if(l==r)
//         return a[l]; 
//     int m=(l+r)>>1;
//     int max1=push_down(l,m);
//     int max2=push_down(m+1,r);
//     int max3=mid(m,l,r);
//     return max(max1,max(max2,max3));
// }
// void solve()
// {
//     cin>>n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin>>a[i];
//     }
//     cout<<push_down(1,n);
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);

//     int t = 1;
//     //cin >> t;
//     while(t --)
//         solve();

//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;   
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=2e5+5;
int a[maxn],n;
struct note
{
    int max_f,max_e,max_s,s;//前缀，后缀，最大子段和，自身
} ;
note sol(int l,int r)
{
    if(l==r)
    {
        note k={a[l],a[l],a[l],a[l]};
            return k;
    }
    int mid=(l+r)>>1;
    note f=sol(l,mid),e=sol(mid+1,r),self;
    self.s=f.s+e.s;
    self.max_f=max(f.max_f,f.s+e.max_f);
    self.max_e=max(e.max_e,f.max_e+e.s);
    self.max_s=max(f.max_s,max(e.max_s,f.max_e+e.max_f));
    return self;
}
void solve()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    cout<<sol(1,n).max_s;
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