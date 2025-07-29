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

const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn = 3.2e4 + 5;

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

struct node
{
    int cost, v, z;
};

bool cmp(const node a, const node b)
{
    if (a.z != b.z)
        return a.z < b.z;
    else
        return a.cost > b.cost;
}

int jian[60] = {}, cnt = 0;
pii zu[60][10] = {};
bool list1[60] = {};
vector<node> oo;
int dp[maxn] = {};

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c; //价格 重要度 依赖
        cin >> a >> b >> c; {
            if (c == 0)
            {
                zu[i][0] = {a, b};
                list1[i] = true;
            } else
            {
                jian[c]++;
                zu[c][jian[c]] = {a, b};
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (list1[i])
        {
            if (jian[i] >= 0)
            {
                node nn;
                nn.cost = zu[i][0].first;
                nn.v = zu[i][0].second * zu[i][0].first;
                nn.z = i;
                oo.push_back(nn);
            }
            if (jian[i] >= 1)
            {
                node nn;
                nn.cost = zu[i][0].first + zu[i][1].first;
                nn.v = zu[i][0].second * zu[i][0].first + zu[i][1].second * zu[i][1].first;
                nn.z = i;
                oo.push_back(nn);
            }
            if (jian[i] >= 2)
            {
                node nn;
                nn.cost = zu[i][0].first + zu[i][1].first + zu[i][2].first;
                nn.v = zu[i][0].second * zu[i][0].first + zu[i][1].second * zu[i][1].first + zu[i][2].second * zu[i][2].
                       first;
                nn.z = i;
                oo.push_back(nn);
                nn.cost = zu[i][0].first + zu[i][2].first;
                nn.v = zu[i][0].second * zu[i][0].first + zu[i][2].second * zu[i][2].first;
                nn.z = i;
                oo.push_back(nn);
            }
        }
    }
    sort(oo.begin(), oo.end(), cmp);
    int p = 0;
    while (p < oo.size())
    {
        int q = p;
        while (q < oo.size() && oo[q].z == oo[p].z) q++;
        for (int j = n; j >= 0; j--)
        {
            for (int k = p; k < q; k++)
            {
                if (j >= oo[k].cost)
                    dp[j] = max(dp[j], dp[j - oo[k].cost] + oo[k].v);
            }
        }
        p = q;
    }
    cout << dp[n] << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();

    return 0;
}
//
// Created by Administrator on 25-7-30.
//
