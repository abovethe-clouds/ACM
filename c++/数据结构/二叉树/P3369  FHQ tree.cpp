#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct Node
{
    int val, priority, size ,l, r;
    Node(int v) : val(v), priority(rng()), size(1), l(0), r(0) {};
    Node() : val(0), priority(0), size(0), l(0), r(0) {};
};
struct FHQ_Treap
{
    vector<Node> tree = vector<Node>(100005);
    int root=0,idx=0;
    int new_node(int val)
    {
        tree[++idx] = Node(val);
        return idx;
    }
    void up(int rt)
    {
        tree[rt].size = tree[tree[rt].l].size + tree[tree[rt].r].size + 1;
    }
    void split(int rt,int k,int &x,int &y)
    {
        if (!rt)
        {
            x=y=0;
            return;
        }
        if (tree[rt].val <= k)
        {
            x=rt;
            split(tree[rt].r,k,tree[rt].r,y);
        }
        else
        {
            y=rt;
            split(tree[rt].l,k,x,tree[rt].l);
        }
        up(rt);
    }
    int merge(int x,int y)
    {
        if (!x||!y)
        {
            return x+y;
        }
        if (tree[x].priority<tree[y].priority)
        {
            tree[x].r=merge(tree[x].r,y);
            up(x);
            return x;
        }
        else
        {
            tree[y].l=merge(x,tree[y].l);
            up(y);
            return y;
        }
    }
    void insert(int v)
    {
        int x,y,z;
        split(root,v,x,y);
        z=new_node(v);
        root=merge(merge(x,z),y);
    }
    void erase(int v)
    {
        int x,y,z;
        split(root,v,x,z);
        split(x,v-1,x,y);
        y=merge(tree[y].l,tree[y].r);
        root=merge(merge(x,y),z);
    }

    int rank(int v)
    {
        int x,y,z;
        split(root,v,x,z);
        split(x,v-1,x,y);
        int ans=0;
        ans=tree[x].size+1;
        root=merge(merge(x,y),z);
        return ans;
    }

    int kth(int rt,int k)
    {
        if (k<=tree[tree[rt].l].size)
            return kth(tree[rt].l,k);
        else if (k==tree[tree[rt].l].size+1)
            return rt;
        else
            return kth(tree[rt].r,k-tree[tree[rt].l].size-1);
    }

    int pre(int v)
    {
        int x,y;
        split(root,v-1,x,y);
        int ans=kth(x,tree[x].size);
        root=merge(x,y);
        return ans;
    }

    int next(int v)
    {
        int x,y;
        split(root,v,x,y);
        int ans=kth(y,1);
        root=merge(x,y);
        return ans;
    }

    int pre_val(int v)
    {
        int x=pre(v);
        return tree[x].val;
    }

    int next_val(int v)
    {
        int x=next(v);
        return tree[x].val;
    }

    int rank_val(int p)
    {
        int x=kth(root,p);
        return tree[x].val;
    }
};
void solve()
{
    FHQ_Treap treap;
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int op,x;
        cin>>op>>x;
        switch (op)
        {
            case 1:
                treap.insert(x);
                break;
            case 2:
                treap.erase(x);
                break;
            case 3:
                cout<<treap.rank(x)<<endl;
                break;
            case 4:
                cout<<treap.rank_val(x)<<endl;
                break;
            case 5:
                cout<<treap.pre_val(x)<<endl;
                break;
            case 6:
                cout<<treap.next_val(x)<<endl;
                break;
        }
    }

}
signed main()
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
}//
// Created by Administrator on 2026/8/24.
//