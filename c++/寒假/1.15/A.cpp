#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
double f(double x,double n)
{
    if(n==1)
        return x/(1+x);
    else
        return x/(n+f(x,n-1));
}
int main()
{
    double a,b;
    cin>>a>>b;
    printf("%.2f",f(a,b));
    return 0;
}