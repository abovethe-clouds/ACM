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
struct cc
{
    ll a,b,c;
};
map<pll,bool> jilu;
void solve()
{
    ll a,b;
    cin>>a>>b;
    cc qi;
    qi.a=a;
    qi.b=b;
    qi.c=0;
    queue<cc> duilie;
    duilie.push(qi);
    while(!duilie.empty())
    {
        cc xin=duilie.front();
        duilie.pop();
        if(xin.a==xin.b)
        {
            cout<<xin.c;
            return;
        }
        	cc fanan1,fanan2,fanan3;
            fanan1.a=xin.a*2;
            fanan1.b=xin.b;
            fanan2.a=xin.a;
            fanan2.b=xin.b-1;
            fanan3.a=xin.a;
            fanan3.b=xin.b+1;
            fanan1.c=xin.c+1;
            fanan2.c=xin.c+1;
            fanan3.c=xin.c+1;
            if(jilu[{fanan1.a,fanan1.b}]==0)
            {
                jilu[{fanan1.a,fanan1.b}]=1;
                duilie.push(fanan1);
            }    
            if(jilu[{fanan2.a,fanan2.b}]==0)
            {
                jilu[{fanan2.a,fanan2.b}]=1;
                duilie.push(fanan2);
            }
            if(jilu[{fanan3.a,fanan3.b}]==0)
            {
                jilu[{fanan3.a,fanan3.b}]=1;
                duilie.push(fanan3);
            }
        
        
    }
    
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