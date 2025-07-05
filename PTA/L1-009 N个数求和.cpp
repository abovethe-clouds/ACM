#include<bits/stdc++.h>
using namespace std;
long long gongbeishu(long long  x,long long y)
{
    long long  a=__gcd(x,y);
    return x*y/a;
}
struct fenshu
{
    long long fenmu=2;
    long long fenzi=0;
    fenshu(){}
    fenshu(long long a,long long b)
    {   
        a=fenzi;
        b=fenmu;
    }
    fenshu operator+ (fenshu a)
    {
        fenshu c;
        c.fenmu=gongbeishu(a.fenmu,fenmu);
        c.fenzi=a.fenzi*(c.fenmu/a.fenmu)+fenzi*(c.fenmu/fenmu);
        return c;
    }
};
fenshu a[100];
int n;
fenshu he;
int zhenShu=0;
void yuefen()
{
    zhenShu+=he.fenzi/he.fenmu;
    he.fenzi%=he.fenmu;
    long long  yueshu=__gcd(he.fenmu,he.fenzi);
    he.fenmu/=yueshu;
    he.fenzi/=yueshu;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%lld/%lld",&a[i].fenzi,&a[i].fenmu);
    }
    for(int i=0;i<n;i++)
    {
        he=a[i]+he;
        yuefen();
    }
    if(he.fenzi==0)
        cout<<zhenShu;
    else
    {
        if(zhenShu==0)
            cout<<he.fenzi<<"/"<<he.fenmu;
        else
            cout<<zhenShu<<" "<<he.fenzi<<"/"<<he.fenmu;
    }
    
}