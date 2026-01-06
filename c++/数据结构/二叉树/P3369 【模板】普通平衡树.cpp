#include<bits/stdc++.h>
#define fir first
#define sec second
using std::pair;
using std::cin;
using std::cout;
using std::max;
using std::min;
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 1e5 + 10;

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

int cnt = 0;
int head = 0; //记录根节点
int key[maxn] = {}; //记录节点的值
int count[maxn] = {}; //记录节点出现的次数
int left[maxn] = {}; //记录左子树
int right[maxn] = {}; //记录右子树
int size[maxn] = {}; //记录子树和头节点的大小
int high[maxn] = {};

void up(int i)
{
    size[i] = size[left[i]] + size[right[i]] + count[i];
    high[i] = max(high[left[i]], high[right[i]]) + 1;
}

int leftRotate(int i) //左旋
{
    int r = right[i];
    right[i] = left[r];
    left[r] = i;
    up(i);
    up(r);
    return r;
}

int rightRotate(int i) //右旋
{
    int l = left[i];
    left[i] = right[l];
    right[l] = i;
    up(i);
    up(l);
    return l;
}

int check(int root)
{
    int r = right[root];
    int l = left[root];
    if (high[l] - high[r] > 1) //L
    {
        if (high[left[l]] >= high[right[l]]) //LL
        {
            root = rightRotate(root);
        }
        else //LR
        {
            left[root] = leftRotate(left[root]);
            root = rightRotate(root);
        }
    }
    else if (high[r] - high[l] > 1) //R
    {
        if (high[right[r]] >= high[left[r]]) //RR
        {
            root = leftRotate(root);
        }
        else //RL
        {
            right[root] = rightRotate(r);
            root = leftRotate(root);
        }
    }
    up(root);
    return root;
}

int _add(int root, int x)
{
    if (root == 0)
    {
        key[++cnt] = x;
        count[cnt] = 1;
        size[cnt] = 1;
        left[cnt] = 0;
        right[cnt] = 0;
        high[cnt] = 1;
        return cnt;
    }
    if (key[root] == x)
    {
        count[root]++;
    }
    else if (key[root] > x)
    {
        left[root] = _add(left[root], x);
    }
    else
    {
        right[root] = _add(right[root], x);
    }
    up(root);
    return check(root);
}

void add(int x)
{
    head = _add(head, x);
}

int small(int root, int x) //返回比x小的数的个数
{
    if (root == 0)
    {
        return 0;
    }
    if (key[root] >= x)
    {
        return small(left[root], x);
    }
    return size[left[root]] + count[root] + small(right[root], x);
}

int getRank(int x) //返回x的排名
{
    return small(head, x) + 1;
}

int _index(int root, int x)
{
    if (size[left[root]] >= x)
    {
        return _index(left[root], x);
    }
    else if (size[left[root]] + count[root] < x)
    {
        return _index(right[root], x - size[left[root]] - count[root]);
    }
    else
        return key[root];
}

int index(int x) //返回排名为x的数
{
    return _index(head, x);
}

int removeMostLeft(int root, int mostLeft)
{
    if (root == mostLeft)
        return right[root];
    left[root] = removeMostLeft(left[root], mostLeft);
    up(root);
    return check(root);
}

int _remove(int root, int x)
{
    if (x > key[root])
        right[root] = _remove(right[root], x);
    else if (x < key[root])
        left[root] = _remove(left[root], x);
    else
    {
        if (count[root] > 1)
        {
            count[root]--;
        }
        else
        {
            if (left[root] == 0 && right[root] == 0)
                return 0;
            else if (left[root] == 0)
                root = right[root];
            else if (right[root] == 0)
                root = left[root];
            else
            {
                int mostLift = right[root];
                while (left[mostLift] != 0)
                {
                    mostLift = left[mostLift];
                }
                right[root] = removeMostLeft(right[root], mostLift);
                left[mostLift] = left[root];
                right[mostLift] = right[root];
                root = mostLift;
            }
        }
    }
    up(root);
    return check(root);
}

void remove(int x)
{
    if (getRank(x) != getRank(x + 1))
    {
        head = _remove(head, x);
    }
}

int _pre(int root, int x)
{
    if (root == 0)
        return -inf;
    if (key[root] >= x)
    {
        return _pre(left[root], x);
    }
    else
    {
        return max(key[root], _pre(right[root], x));
    }
}

int pre(int x)
{
    return _pre(head, x);
}

int _next(int root, int x)
{
    if (root == 0)
        return inf;
    if (key[root] <= x)
    {
        return _next(right[root], x);
    }
    else
    {
        return min(key[root], _next(left[root], x));
    }
}

int next(int x)
{
    return _next(head, x);
}

void solve()
{
    int n = read();
    for (int i = 1; i <= n; i++)
    {
        int op = read(), x = read();
        if (op == 1)
        {
            add(x);
        }
        else if (op == 2)
        {
            remove(x);
        }
        else if (op == 3)
        {
            cout << getRank(x) << endl;
        }
        else if (op == 4)
        {
            cout << index(x) << endl;
        }
        else if (op == 5)
        {
            cout << pre(x) << endl;
        }
        else
        {
            cout << next(x) << endl;
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //t=read();
    while (t--)
        solve();
    return 0;
}

//
// Created by Administrator on 2025/12/18.
//
