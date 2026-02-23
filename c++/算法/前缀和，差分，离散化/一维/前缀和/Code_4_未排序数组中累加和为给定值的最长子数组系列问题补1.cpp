//https://www.nowcoder.com/practice/545544c060804eceaed0bb84fcd992fb
#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int ll
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x * w;
}

void solve() {
    int n = read(), l = -1;
    vector<int> a(n + 1), pre(n + 1);
    unordered_map<int, int> mp;
    auto is=[](int x) {
        if (x > 0) return 1;
        else if (x == 0) return 0;
        else return -1;
    };
    mp[0] = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = read();
        pre[i] = pre[i - 1] + is(a[i]);
        if (mp.find(pre[i]) == mp.end())
            mp[pre[i]] = i;
        l = max(l, (mp.count(pre[i]) ? (i - mp[pre[i]]) : 0));
    }

    cout << l << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //t = read();
    while (t--)
        solve();
    return 0;
}
