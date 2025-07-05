#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

struct Op {
    int t, idx;          // 操作类型 & 位置
};
const int N = 45;         // n ≤ 40

int n;
int a[N], b[N];
vector<Op> ops;

// 记录并执行一次操作
void do_swap(int type, int idx)
{
    if (type == 1) swap(a[idx], a[idx + 1]);
    else if (type == 2) swap(b[idx], b[idx + 1]);
    else swap(a[idx], b[idx]);      // type == 3
    ops.push_back({type, idx});
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    ops.clear();

    for (int i = 1; i <= n; ++i)
    {
        int needOdd  = 2 * i - 1;   // 应放到 a[i]
        int needEven = 2 * i;       // 应放到 b[i]

        /* ---------- 处理奇数 ---------- */
        int posOdd = -1; bool inA = false;
        for (int j = i; j <= n; ++j)
        {
            if (a[j] == needOdd) { posOdd = j; inA = true;  break; }
            if (b[j] == needOdd) { posOdd = j; inA = false; break; }
        }
        if (!inA)                  // 在 b 列：先纵向 3
            do_swap(3, posOdd);    // now needOdd 在 a[posOdd]

        for (int k = posOdd - 1; k >= i; --k)   // 冒泡到 a[i]
            do_swap(1, k);

        /* ---------- 处理偶数 ---------- */
        int posEven = -1; bool inB = false;
        for (int j = i; j <= n; ++j)
        {
            if (b[j] == needEven) { posEven = j; inB = true;  break; }
            if (a[j] == needEven) { posEven = j; inB = false; break; }
        }
        if (!inB)                  // 在 a 列：先纵向 3
            do_swap(3, posEven);   // now needEven 在 b[posEven]

        for (int k = posEven - 1; k >= i; --k)  // 冒泡到 b[i]
            do_swap(2, k);
    }

    /* ---------- 输出 ---------- */
    cout << ops.size() << endl;
    for (auto &op : ops) cout << op.t << ' ' << op.idx << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;               // 多组数据
    if (!(cin >> T)) return 0;
    while (T--) solve();
    return 0;
}
