// c++
#include <bits/stdc++.h>
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

// 快速读整数（处理负数），使用 getchar 提高读取速度
int read()
{
    int x = 0, w = 1;
    char ch = 0;
    // 跳过非数字字符，记录负号
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    // 读数字
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

// 处理每个测试用例：将 n 转换为 y 进制并求各位之和
void solve()
{
    int n = read(), y = read(); // 读入 n 和进制 y
    // 特殊情况：y <= 1 时不能正常作为进制处理
    // 如果 y == 1，则把 n 表示为 n 个 1，位数和为 n（若 y <= 0 也视作非法，按同样处理）
    if (y <= 1)
    {
        cout << n << endl;
        return;
    }
    int sum = 0;
    // 使用循环除法逐位获取 y 进制各位并累加，避免预先分配或对数计算带来的问题
    while (n > 0)
    {
        sum += n % y; // 当前位
        n /= y;       // 进入更高一位
    }
    cout << sum << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // 本地调试时可以取消注释重定向输入输出
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    t = read(); // 首行为测试用例数量
    while (t--)
        solve();
    return 0;
}