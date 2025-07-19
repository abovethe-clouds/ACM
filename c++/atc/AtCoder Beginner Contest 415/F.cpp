#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131,maxn=5e5+5;
struct point
{
    char front, in, end;
    int front_num, in_num, end_num,l;
};
string s;
point tree[4 * maxn];
int ls(int x)
{
    return x * 2;
}
int rs(int x)
{
    return x * 2 + 1;
}
point merge(point a,point b)
{
    point c;
    c.l = a.l + b.l; //l
    c.in_num = 0;


    if(a.end==b.front)
    {
        c.in_num = a.end_num + b.front_num; //in in_num
        c.in = a.end;
    }
    if(a.in_num>c.in_num)
    {
        c.in_num = a.in_num;
        c.in = a.in;
    }
    if (b.in_num > c.in_num)
    {
        c.in_num = b.in_num;
        c.in = b.in;
    }



    c.front = a.front;//front front_num
    if (a.front_num == a.l && a.in == b.front)
    {
        c.front_num = a.l + b.front_num;  
    }
    else
    {
        c.front_num = a.front_num;
    }
    c.end = b.end; // end end_num

    
    if (b.front_num == b.l && a.end == b.front)
    {
        c.end_num = a.end_num + b.l;
    }
    else
    {
        c.end_num = b.end_num;
    }
    return c;
}
point push_up(int root)
{
    return tree[root]=merge(tree[ls(root)], tree[rs(root)]);
}
point make(char ch)
{
    point a;
    a.end = ch;
    a.end_num = 1;
    a.front = ch;
    a.front_num = 1;
    a.in = ch;
    a.in_num = 1;
    a.l = 1;
    return a;
}
void built(int root,int l,int r)
{
    if(l==r)
    {
        tree[root] = make(s[l - 1]);
        return;
    }
    int mid = (l + r) / 2;
    built(ls(root), l, mid);
    built(rs(root), mid + 1, r);
    push_up(root);
    return;
}
void change(int root,int where,int l,int r,char ch)
{
    if(where==l&&l==r)
    {
        tree[root] = make(ch);
        return;
    }
    int mid = (l + r) / 2;
    if(where<=mid)
        change(ls(root), where, l, mid, ch);
    else
        change(rs(root), where, mid+1, r, ch);
    push_up(root);
}
point find(int root,int find_l,int find_r,int root_l,int root_r)
{
    if (find_l == root_l && find_r == root_r)
    {
        return tree[root];
    }
    int mid = (root_l + root_r) / 2;
    if(find_r<=mid)
        return find(ls(root), find_l, find_r, root_l, mid);
    if(find_l>mid)
        return find(rs(root), find_l, find_r, mid + 1, root_r);
    return merge(find(ls(root), find_l, mid, root_l, mid), find(rs(root), mid + 1, find_r, mid + 1, root_r));
}
void solve()
{
    int n, q;
    cin >> n >> q >> s;
    built(1, 1, n);
    while (q--)
    {
        int op;
        cin >> op;
        if(op==1)
        {
            int i;
            char ch;
            cin >> i >> ch;
            change(1, i, 1, n, ch);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            point ans = find(1, l, r, 1, n);
            cout << ans.in_num << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        //freopen("test.in", "r", stdin);
       // freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    while(t--)
        solve();

    return 0;
}