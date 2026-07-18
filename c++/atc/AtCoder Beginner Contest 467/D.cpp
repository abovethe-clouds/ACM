#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const double eps = 1e-9;

struct pt
{
    double x, y;

    pt operator+(pt p) { return {x + p.x, y + p.y}; }

    pt operator-(pt p) { return {x - p.x, y - p.y}; }

    pt operator*(double k) { return {x * k, y * k}; }

    pt operator/(double k) { return {x / k, y / k}; }
};

double cross(pt a, pt b)
{
    return a.x * b.y - a.y * b.x;
}

double sq(pt a)
{
    return a.x * a.x + a.y * a.y;
}

pt perp(pt a)
{
    return {-a.y, a.x};
}

struct line
{
    pt v;
    double c;
    line(pt v, double c):v(v),c(c){}
    double side(pt p)
    {
        return cross(v,p)-c;
    }
};

line perpendicularBisector(pt a, pt b)
{
    pt mid=(a+b)/2.0;
    pt dir=perp(b-a);

    return line(dir,cross(dir,mid));
}

// 求交点(非平行)
bool inter(line a,line b)
{
    return fabs(cross(a.v,b.v))>eps;
}


// 判断两条线是否重合
bool sameLine(line a,line b)
{
    if(fabs(cross(a.v,b.v))>eps)
        return false;

    // 找 b 上一点
    pt p=perp(b.v)*(b.c/sq(b.v));

    return fabs(a.side(p))<eps;
}


void solve()
{
    pt p,q,r,s;

    cin>>p.x>>p.y
       >>q.x>>q.y
       >>r.x>>r.y
       >>s.x>>s.y;


    line l1=perpendicularBisector(p,q);
    line l2=perpendicularBisector(r,s);


    if(inter(l1,l2)||sameLine(l1,l2))
        cout<<"Yes\n";
    else
        cout<<"No\n";
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
        solve();
}