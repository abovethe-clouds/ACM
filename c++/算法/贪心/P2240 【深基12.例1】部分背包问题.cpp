#include<bits/stdc++.h>
using namespace std;
struct coin
{
	double m;
	double v;
	double jiage;
	coin() {}
	coin (double c,double d)
	{
		m=c;
		v=d;
	}
};
int jiangxu(coin x,coin y)
{
	return x.jiage>y.jiage;
}
int main()
{
    int n,t;double sum=0,money=0;
    coin q[100];
    cin>>n>>t;
    for(int i=0;i<n;i++)
    {
    	cin>>q[i].m>>q[i].v;
    	q[i].jiage=q[i].v/q[i].m;
	}
	sort(q,q+n,jiangxu);
	for(int i=0;i<n;i++)
	{
        if(t>= q[i].m)
		{
            t-= q[i].m;
            sum+= q[i].v;
        }
        else{
            sum+= q[i].jiage*t;
            break;
        }
    }
    printf("%.2f",sum);
    return 0;
}