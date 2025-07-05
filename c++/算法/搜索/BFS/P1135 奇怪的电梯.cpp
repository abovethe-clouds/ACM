#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
int K[200],a,b,k,julu[200],tu[200];
void solve()
{
    cin>>k>>a>>b;
    a--,b--;
    for (int i = 0; i < k; i++)
    {
        cin>>K[i];
    }
    queue<pii> oo;
    pii c;
    c.first=a;
    c.second=0;
    oo.push(c);
    while(!oo.empty())
    {
        pii ah=oo.front();
        julu[ah.first]=1;
        tu[ah.first]=ah.second;
        oo.pop();
        for(int i=-1;i<=1;i+=2)
        {
            pii dian;
            dian.first=ah.first+(i*K[(ah.first)]);
            dian.second=ah.second+1;
            if(dian.first<=k&&dian.first>=0&&julu[dian.first]==0)
            {
                oo.push(dian);
                julu[dian.first]=1;
            }
        }

    }
    if(julu[b]==1)
        cout<<tu[b];    
    else
        cout<<-1;
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