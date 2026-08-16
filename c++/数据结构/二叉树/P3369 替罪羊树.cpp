#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int long long
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
struct tree
{
    vector<int> count,right,left,size,key,diff,dfs;
    double alpha=0.7;
    int cnt=0,top=0,father,head,side;
    int insert_num(int num)
    {
        size[++cnt]=1;
        key[cnt]=num;
        left[cnt]=right[cnt]=0;
        count[cnt]=1;
        diff[cnt]=1;
        return cnt;
    }
    void up(int rt)
    {
        size[rt]=size[left[rt]]+size[right[rt]]+count[rt];
        diff[rt]=diff[left[rt]]+diff[right[rt]]+(count[rt]>0?1:0);
    }
    bool is_no(int rt)
    {
        double ans=alpha*diff[rt];
        if (diff[right[rt]]>ans||diff[left[rt]]>ans)
            return true;
        return false;
    }
    void add(int rt,int f,int s,int num)
    {
        if (rt==0)
        {
            if (f==0)
            {
                head=insert_num(num);
            }
            else if (side==1)
            {
                left[f]=insert_num(num);
            }
            else
            {
                right[f]=insert_num(num);
            }
            return;
        }
        else
        {
            if (key[rt]==num)
            {
                count[rt]++;
                up(rt);
            }
            else
            {
                if (key[rt]>num)
                {
                    side=1;
                    add(left[rt],rt,1,num);
                }
                else
                {
                    side=2;
                    add(right[rt],rt,2,num);
                }
            }
        }
        up(rt);
        if (is_no(rt))
        {
            top=rt;
            father=f;
            side=s;
        }
        return;
    }
    void insert(int x)
    {
        father=top=side=0;
        add(head,0,0,x);
        rebuild();
    }
    void _dfs(int rt)
    {
        if (!rt)
            return;
        _dfs(left[rt]);
        if (count[rt]>0)
            dfs.push_back(rt);
        _dfs(right[rt]);
    }
    int re_built(int l,int r)
    {
        if (l>r)
            return 0;
        int mid=(l+r)/2;
        int rt=dfs[mid];
        left[rt]=re_built(l,mid-1);
        right[rt]=re_built(mid+1,r);
        up(rt);
        return rt;
    }
    void rebuild()
    {
        if (top==0)
            return;
        dfs.clear();
        _dfs(top);
        if (dfs.size()==0)
            return;
        if (father==0)
        {
            head=re_built(0,dfs.size()-1);
        }
        else
        {
            if (side==1)
            {
                left[father]=re_built(0,dfs.size()-1);
            }
            else
            {
                right[father]=re_built(0,dfs.size()-1);
            }

        }
    }
    void _remove(int rt,int f,int s,int num)
    {
        if (key[rt]==num)
        {
            count[rt]--;

        }
        else
        {
            if (key[rt]>num)
            {
                _remove(left[rt],rt,1,num);
            }
            else
            {
                _remove(right[rt],rt,2,num);
            }
        }
        up(rt);
        if (is_no(rt))
        {
            top=rt;
            father=f;
            side=s;
        }
    }
    void del(int num)
    {
        if (rank(num)!=rank(num+1))
        {
            top=father=side=0;
            _remove(head,0,0,num);
            rebuild();
        }
    }
    int small(int i,int num)
    {
        if (i==0)
            return 0;
        if (key[i]>=num)
            return small(left[i],num);
        else
            return size[left[i]]+count[i]+small(right[i],num);
    }
    int rank(int num)
    {
        return small(head,num)+1;
    }
    int index(int i,int num)
    {
        if (size[left[i]]>=num)
            return index(left[i],num);
        else if (size[left[i]]+count[i]>=num)
            return key[i];
        else
            return index(right[i],num-size[left[i]]-count[i]);
    }
    int index(int num)
    {
        return index(head,num);
    }
    int pre(int num)
    {
        int th=rank(num);
        if (th==1)
            return 0;
        return index(th-1);
    }
    int post(int num)
    {
        int th=rank(num+1);
        if (th==size[head]+1)
            return 0;
        return index(th);
    }
    tree(int num)
    {
        count.resize(num + 5, 0);
        right.resize(num + 5, 0);
        left.resize(num + 5, 0);
        size.resize(num + 5, 0);
        key.resize(num + 5, 0);
        dfs.resize(num + 5, 0);
        diff.resize(num + 5, 0);
        head = 0, cnt = 0;
    }
};
void solve()
{
    int n;
    cin>>n;
    tree t(n);
    while (n--)
    {
        int op,x;
        cin>>op>>x;
        if (op==1)
        {
            t.insert(x);
        }
        else if (op==2)
        {
            t.del(x);
        }
        else if (op==3)
        {
            cout<<t.rank(x)<<endl;
        }
        else if (op==4)
        {
            cout<<t.index(x)<<endl;
        }
        else if (op==5)
        {
            cout<<t.pre(x)<<endl;
        }
        else if (op==6)
        {
            cout<<t.post(x)<<endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    while (t--)
        solve();
    return 0;
}
//
// Created by Administrator on 2026/8/16.
//