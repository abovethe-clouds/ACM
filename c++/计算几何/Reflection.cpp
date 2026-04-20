//https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_B
//https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_A
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

struct pt
{
    double x, y;

    pt operator+(pt p)
    {
        return {x + p.x, y + p.y};
    }

    pt operator-(pt p)
    {
        return {x - p.x, y - p.y};
    }

    pt operator*(double d)
    {
        return {x * d, y * d};
    }

    pt operator/(double d)
    {
        return {x / d, y / d};
    }
};

struct line
{
    pt p1, p2, v;

    line(pt p1, pt p2)
    {
        this->p1 = p1;
        this->p2 = p2;
        v = p2 - p1;
    }

    double dot(line o)
    {
        double ans = o.v.x * v.x + o.v.y * v.y;
        return ans;
    }

    double lengthNoSqrt()
    {
        return v.x * v.x + v.y * v.y;
    }

    double length()
    {
        return sqrt(lengthNoSqrt());
    }

    pt operator*(double k)
    {
        return {v.x * k, v.y * k};
    }

    pt operator/(double k)
    {
        return {v.x / k, v.y / k};
    }
};

void solve()
{
    pt pt1, pt2;
    cin >> pt1.x >> pt1.y >> pt2.x >> pt2.y;
    line l(pt1, pt2);
    int q;
    cin >> q;
    cout << fixed << setprecision(10);
    while (q--)
    {
        pt o;
        cin >> o.x >> o.y;
        line ol(pt1, o);
        pt ans = pt1 + (l.v * ol.dot(l) / l.lengthNoSqrt());
        cout << ans.x * 2 -o.x << " " << ans.y *2 - o.y << endl;
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
