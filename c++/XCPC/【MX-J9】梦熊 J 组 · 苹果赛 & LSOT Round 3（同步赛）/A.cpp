#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int N = 1e5, M = N * 2, mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
bool gaofenbaoli(int x)
{
    if(x>=45&&x<=84)
        return true;
    return false;
}
bool tongguo(int x)
{
    if(x>=85&&x<=100)
        return true;
    return false;
}
bool difeng(int x)
{
    if(x>=25&&x<=44)
        return true;
    return false;
}
bool zishu(int x)
{
    if(x>=1&&x<=24)
        return true;
    return false;
}
void solve()
{
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    if((gaofenbaoli(a[2])&&difeng(a[1])&&zishu(a[0]))||(tongguo(a[2])&&gaofenbaoli(a[1])&&difeng(a[0]))||(tongguo(a[2])&&tongguo(a[1])&&(difeng(a[0])||gaofenbaoli(a[0])))||(tongguo(a[0])&&tongguo(a[1])&&tongguo(a[2])))
        cout<<"Yes";
    else
        cout<<"No";

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(t --)
        solve();

    return 0;
}