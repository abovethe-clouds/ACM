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
    char c;
    int l,r,pri,size;
    Node(char _c) : c(_c), l(0), r(0), size(1), pri(rng()) {};
    Node() : c(0), l(0), r(0), size(0), pri(0) {};
};
struct FHQ_Treap
{
    vector<Node> tree=vector<Node>(2100000);
    int root=0,idx=0;
    int new_node(char c)
    {
        tree[++idx]=Node(c);
        return idx;
    }
    void up(int rt)
    {
        tree[rt].size=tree[tree[rt].l].size+tree[tree[rt].r].size+1;
    }
    void split(int rt,int k,int &x,int &y)
    {
        if (!rt)
        {
            x=y=0;
            return;
        }
        if (tree[tree[rt].l].size<k)
        {
            x=rt;
            split(tree[rt].r,k-tree[tree[rt].l].size-1,tree[rt].r,y);
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
        if (tree[x].pri<tree[y].pri)
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
    void insert(int pos,string s)
    {
        int x,y;
        split(root,pos,x,y);
        for (char c : s)
        {
            x=merge(x,new_node(c));
        }
        root=merge(x,y);
    }
    void erase(int pos,int len)
    {
        int x,y,z;
        split(root,pos,x,y);
        split(y,len,y,z);
        root=merge(x,z);
    }
    void print(int pos,int n)
    {
        int x,y,z;
        split(root,pos,x,y);
        split(y,n,y,z);
        function<void(int)> dfs = [&](int rt)
        {
            if (!rt)
                return;
            dfs(tree[rt].l);
            cout<<tree[rt].c;
            dfs(tree[rt].r);
        };
        dfs(y);
        root=merge(merge(x,y),z);
    }
};
void solve()
{
    FHQ_Treap treap;
    int n,GB=0;
    cin>>n;
    while (n--)
    {
        string op;
        cin>>op;
        if (op=="Move")
        {
            cin>>GB;
        }
        else if (op == "Insert")
        {
            int len;
            cin >> len;
            string s;
            s.reserve(len);
            while (s.size() < len)
            {
                char ch = cin.get();
                if (ch == EOF) break;
                if (ch >= 32 && ch <= 126)
                    s.push_back(ch);
            }
            treap.insert(GB, s);
        }
        else if (op=="Delete")
        {
            int len;
            cin>>len;
            treap.erase(GB,len);
        }
        else if (op=="Get")
        {
            int len;
            cin>>len;
            treap.print(GB,len);
            cout<<endl;
        }
        else if (op=="Prev")
        {
            GB--;
        }
        else if (op=="Next")
        {
           GB++;
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