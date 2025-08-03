#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=2e5+5;
struct point
{
    pii lazy,sum;

};
int lcm(int a,int b)
{
    return (a*b)/__gcd(a,b);
}
point tree[maxn*4];
pii add(pii a,pii b)
{
    pii ans;
    int fenzia=a.first;
    int fenzib=b.first;
    int fenmua=a.second;
    int fenmub=b.second;
    if (fenmua==fenzib)
    {
        ans.first=fenzia+fenzib;
        ans.second=fenmua;
        return ans;
    }
    ans.second=lcm(fenmua,fenmub);
    fenzia=ans.second/fenmua*fenzia;
    fenzib=ans.second/fenmub*fenzib;
    ans.first=fenzia+fenzib;
    return ans;
}
pii div(pii a,int x)
{
    pii ans;
    ans.second=a.second*x;
    ans.first=a.first;
    int gcd=lcm(ans.first,ans.second);
    ans.first/=gcd;
    ans.second/=gcd;
    return ans;
}
point merge(point a,point b)
{
    point m;
    m.lazy={0,0};
    m.sum=add(a.sum,b.sum);
    return m;
}
void push_down(int root,int l,int r)
{

}
void these_change(int root,int l,int r,int l1,int r1)//l,r改的范围，l1,r1根节点包含的范围,add加
{
    if(tree[root].lazy.first!=-1||tree[root].lazy.secondQ=-1)
        push_down(root,l1,r1);
    int mid=l1+(r1-l1)/2;
    if(l==l1&&r==r1)//同个区间
    {
        tree[root].lazy.;
    }
    else
    {
        if(r<=mid)
        {
            these_change(root*2,l,r,l1,mid);
        }
        else
        {
            if(l>mid)
            {

                these_change(root*2+1,l,r,mid+1,r1);
            }
            else
            {
                these_change(root*2,l,mid,l1,mid);
                these_change((root*2)+1,mid+1,r,mid+1,r1);
            }
        }
    }
    return;
}
int read()
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

void solve()
{

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
