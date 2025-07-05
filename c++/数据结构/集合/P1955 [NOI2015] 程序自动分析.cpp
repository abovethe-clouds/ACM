#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=1e5+5;
int n,m,l,r,e,fa[maxn*2];
struct stu
{
    int x,y,e;
    bool const operator<(const stu &p)
    {
        return p.e<e;
    }
};
int find(int x)
{
    if(x==fa[x])
        return x;
    else
        return fa[x]=find(fa[x]);
}
void add(int x,int y)
{
    fa[find(fa[x])]=find(y);
    return;
}
void solve()
{
    cin>>n;
    vector<int> q;
    for (int i = 0; i < n*2; i++)
    {
        fa[i]=i;
    }
    stu tree[n];
    for (int o = 0; o < n; o++)
    {
        cin>>l>>r>>e;
        q.push_back(l);
        q.push_back(r);
        tree[o]={l,r,e};
    }
    sort(q.begin(),q.end());
    q.erase(unique(q.begin(),q.end()),q.end());
    for (int i = 0; i < n; i++)
    {
        tree[i].x=lower_bound(q.begin(),q.end(),tree[i].x)-q.begin();
        tree[i].y=lower_bound(q.begin(),q.end(),tree[i].y)-q.begin();
    }
    
    sort(tree,tree+n);
    for (int i = 0; i < n; i++)
    {
        if(tree[i].e==1)
            add(tree[i].x,tree[i].y);
        else
        {
            if(find(tree[i].x)==find(tree[i].y))
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    return;
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t --)
        solve();

    return 0;
}