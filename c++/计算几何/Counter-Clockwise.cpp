// https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_C
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

    bool operator==(pt p)
    {
        return x == p.x && y == p.y;
    }

    bool operator!=(pt p)
    {
        return !((pt){x, y} == p);
    }

    bool operator<(const pt &p) const
    {
        return ((pair<double, double>){x, y}) <
               ((pair<double, double>){p.x, p.y});
    };
};

// 距离的平方
double sq(pt p)
{
    return p.x * p.x + p.y * p.y;
}

// 距离
double abs(pt p)
{
    return sqrt(sq(p));
};
// debug过程中使用
ostream &operator<<(ostream &os, pt p)
{
    return os << "(" << p.x << ", " << p.y << ")";
}

// sgn函数,小于零返回-1,大于零返回1
int sgn(double x)
{
    return (double(0) < x) - (x < double(0));
}

// 平移,也即向量求和
pt translate(pt v, pt p)
{
    return p + v;
}

// 以c为中心进行缩放,倍率为factor
pt sclae(pt c, double factor, pt p)
{
    return c + (p - c) * factor;
}

// 逆时针旋转
pt rot(pt p, double a)
{
    return {p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a)};
}

// 逆时针旋转九十度
pt perp(pt p)
{
    return {-p.y, p.x};
}

// 点积
double dot(pt v, pt w)
{
    return v.x * w.x + v.y * w.y;
}
// 判断是否垂直
bool isPerp(pt v, pt w)
{
    return dot(v, w) == 0;
}

// 求向量夹角
double angle(pt v, pt w)
{
    double cosTheta = dot(v, w) / abs(v) / abs(w);
    return acos(max(-1.0, min(1.0, cosTheta)));
}

// 叉积
double cross(pt v, pt w)
{
    return v.x * w.y - v.y * w.x;
}

// 判断三个点是否为逆时针排布, 共线返回0
double orient(pt a, pt b, pt c)
{
    return cross(b - a, c - a);
}

// 判断P是否在∠BAC内
bool inAngle(pt a, pt b, pt c, pt p)
{
    assert(orient(a, b, c) != 0);
    if (orient(a, b, c) < 0) swap(b, c);
    return orient(a, b, p) >= 0 && orient(a, c, p) <= 0;
}

// 返回旋转角∠BAC
double orientedAngle(pt a, pt b, pt c)
{
    if (orient(a, b, c) >= 0)
    {
        return angle(b - a, c - a);
    }
    else
    {
        return 2 * M_PI - angle(b - a, c - a);
    }
}

// 这是一个双关键字排序,对极角进行排序,第二关键字为距离,中间点不能包含零.
bool half(pt p)
{
    assert(p.x != 0 || p.y != 0);
    return p.y > 0 || (p.y == 0 && p.x < 0);
}

void polarSort(vector<pt> &v)
{
    sort(v.begin(), v.end(), [](pt v, pt w)
    {
        return make_tuple(half(v), 0, sq(v)) <
               make_tuple(half(w), cross(v, w), sq(w));
    });
}

// 线的封装模板,用方向向量和偏移量定义直线
struct line
{
    pt v;
    double c;

    line(pt v, double c) : v(v), c(c)
    {
    }

    line(double a, double b, double c) : v({b, -a}), c(c)
    {
    }

    line(pt p, pt q) : v(q - p), c(cross(v, p))
    {
    }

    // 判断点在线的positive side还是negative side面
    double side(pt p)
    {
        return cross(v, p) - c;
    }

    // 点到直线距离
    double dist(pt p)
    {
        return abs(side(p)) / abs(v);
    }

    // 点到直线距离的平方
    double sqDist(pt p)
    {
        return side(p) * side(p) / (double) sq(v);
    }

    // 返回过点p的垂线
    line perpThrough(pt p)
    {
        return {p, p + perp(v)};
    }

    // 沿直线排序的布尔,可以直接基于这个调用sort
    bool cmpProj(pt p, pt q)
    {
        return dot(v, p) < dot(v, q);
    }

    // 沿指定方向平移
    line translate(pt t)
    {
        return {v, c + cross(v, t)};
    }

    // 计算投影点
    pt proj(pt p)
    {
        return p - perp(v) * side(p) / sq(v);
    }

    //计算对称点
    pt refl(pt p)
    {
        return p - perp(v) * 2 * side(p) / sq(v);
    }
};

// 判断直线是否平行并返回交点
bool inter(line l1, line l2, pt &out)
{
    double d = cross(l1.v, l2.v);
    if (d == 0) return false;
    out = (l2.v * l1.c - l1.v * l2.c) / d;
    return true;
}

// 判断p是否在以AB为直径的圆上
bool inDisk(pt a, pt b, pt p)
{
    return dot(a - p, b - p) <= 0;
}

// 判断P是否在线段AB上
bool onSegment(pt a, pt b, pt p)
{
    return orient(a, b, p) == 0 && inDisk(a, b, p);
}

// 判断是否有交点
bool properInter(pt a, pt b, pt c, pt d, pt &out)
{
    double oa = orient(c, d, a), ob = orient(c, d, b),
           oc = orient(a, b, c), od = orient(a, b, d);
    // Proper intersection exists iff opposite signs
    if (oa * ob < 0 && oc * od < 0)
    {
        out = (a * ob - b * oa) / (ob - oa);
        return true;
    }
    return false;
}

// s = 1则只有一个交点, s = 2则有线段重合,s中即为重合线段
set<pt> inters(pt a, pt b, pt c, pt d)
{
    pt out;
    if (properInter(a, b, c, d, out)) return {out};
    set<pt> s;
    if (onSegment(c, d, a)) s.insert(a);
    if (onSegment(c, d, b)) s.insert(b);
    if (onSegment(a, b, c)) s.insert(c);
    if (onSegment(a, b, d)) s.insert(d);
    return s;
}

// 点到线段的距离
double segPoint(pt a, pt b, pt p)
{
    if (a != b)
    {
        line l(a, b);
        if (l.cmpProj(a, p) && l.cmpProj(p, b))
            return l.dist(p);
        return min(abs(p - a), abs(p - b));
    }
    return abs(p - a);
}

// 线段到线段的距离
double segSeg(pt a, pt b, pt c, pt d)
{
    pt dummy;
    if (properInter(a, b, c, d, dummy)) return 0;
    return min({
        segPoint(a, b, c), segPoint(a, b, d), segPoint(c, d, a), segPoint(c, d,
                                                                          b)
    });
}

// 多边形面积
double areaPolygon(vector<pt> p)
{
    double area = 0.0;
    for (int i = 0, n = p.size(); i < n; i++)
    {
        area += cross(p[i], p[(i + 1) % n]);
    }
    return abs(area) / 2.0;
}

// 判断p是否比a高（包含相同）
bool above(pt a, pt p)
{
    return p.y >= a.y;
}

// 判断PQ是否被A发送的射线穿过（包含上界，不含下界）
bool crossesRay(pt a, pt p, pt q)
{
    return (above(a, q) - above(a, p)) * orient(a, p, q) > 0;
}

// 判断A是否在多边形内
bool inPolygon(vector<pt> p, pt a, bool strict = true)
{
    int numCrossings = 0;
    for (int i = 0, n = p.size(); i < n; i++)
    {
        if (onSegment(p[i], p[(i + 1) % n], a)) return !strict;
        numCrossings += crossesRay(a, p[i], p[(i + 1) % n]);
    }
    return numCrossings & 1;
}

// 判断这三个点的连线是否为“左转关系”
bool turn_left(pt a, pt b, pt c)
{
    return sgn(cross(b - a, c - a)) > 0;
}

// 返回点集的凸包(凸多边形包含内部所有点)
vector<pt> convex_hull(vector<pt> a)
{
    if (a.size() <= 2) return a;
    pt base = *min_element(a.begin(), a.end()); // 查找最小的元素
    vector<pt> time_a;
    for (pt i: a)
        if (i != base)
            time_a.push_back(i);
    sort(time_a.begin(), time_a.end(), [&](auto v, auto w)
    {
        if (make_tuple(half(v - base), 0) < make_tuple(half(w - base), cross(v - base, w -
                                                                                 base)))
            return true;
        else if (make_tuple(half(v - base), 0) == make_tuple(half(w - base), cross(v - base,
                                                                 w - base)) && sq(v - base) < sq(w - base))
            return true;
        else return false;
    });
    a.clear();
    a.push_back(base);
    for (pt i: time_a)
        a.push_back(i);
    vector<pt> ret;
    for (auto i: a)
    {
        while (ret.size() > 1 && !turn_left(ret[ret.size() - 2], ret[ret.size() - 1], i))
            ret.pop_back();
        ret.push_back(i);
    }
    return ret;
}

// 外接圆圆心
pt circumCenter(pt a, pt b, pt c)
{
    b = b - a, c = c - a;
    assert(cross(b, c) != 0);
    return a + perp(b * sq(c) - c * sq(b) / cross(b, c) / 2);
}

// 圆和直线交点数量
int circleLine(pt o, double r, line l, pair<pt, pt> &out)
{
    double h2 = r * r - l.sqDist(o);
    if (h2 >= 0)
    {
        pt p = l.proj(o);
        pt h = l.v * sqrt(h2) / abs(l.v);
        out = {p - h, p + h};
    }
    return 1 + sgn(h2);
}

// 圆和圆之间交点
int circleCircle(pt o1, double r1, pt o2, double r2, pair<pt, pt> &out)
{
    pt d = o2 - o1;
    double d2 = sq(d);
    if (d2 == 0)
    {
        assert(r1 != r2);
        return 0;
    }
    double pd = (d2 + r1 * r1 - r2 * r2) / 2;
    double h2 = r1 * r1 - pd * pd / 2;
    if (h2 >= 0)
    {
        pt p = o1 + d * pd / d2, h = perp(d) * sqrt(h2 / d2);
        out = {p - h, p + h};
    }
    return 1 + sgn(h2);
}

void solve()
{
    pt a, b;
    cin>>a.x>>a.y>>b.x>>b.y;
    line l1 = {a, b};
    int q;
    cin>>q;
    while (q--)
    {
        pt c;
        cin>>c.x>>c.y;
        line l2 = {a, c};
        if (cross(b-a, c-a) == 0)//三点共线
        {
            pt v = b - a;
            pt w = c - a;

            if (dot(v, w) < 0)
            {
                cout << "ONLINE_BACK\n";
            }
            else if (sq(v) < sq(w))
            {
                cout << "ONLINE_FRONT\n";
            }
            else
            {
                cout << "ON_SEGMENT\n";
            }
        }
        else
        {
            if (cross(b-a, c-a) > 0)
                cout<<"COUNTER_CLOCKWISE"<<endl;
            else
                cout<<"CLOCKWISE"<<endl;
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
