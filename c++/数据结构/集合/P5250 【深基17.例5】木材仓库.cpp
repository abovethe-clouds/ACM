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
set<int> o;
void solve()
{
    int n;
    cin>>n;
    while (n--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int p;
            cin>>p;
            if(!o.insert(p).second)
                cout<<"Already Exist"<<endl;
        }
        else
        {
            int p;
            cin>>p;
            if(o.find(p)!=o.end())
            {
                cout<<p<<endl;
                o.erase(p);
            }
            else if(o.empty())
                cout<<"Empty"<<endl;
            else
            {
                auto q=o.lower_bound(p);
                if(q==o.begin())
                {
                    cout<<*q<<endl;
                    o.erase(*q);
                }
                else if(q==o.end())
                {
                    q--;
                    cout<<*q<<endl;
                    o.erase(*q);
                }
                else
                {
                    auto w=q;
                    w--;
                    if(abs(*w-p)<abs(*q-p))
                    {
                        cout<<*w<<endl;
                        o.erase(*w);
                    }
                    else if(abs(*w-p)==abs(*q-p))
                    {
                        cout<<*w<<endl;
                        o.erase(*w);
                    }
                    else
                    {
                        cout<<*q<<endl;
                        o.erase(*q);
                    }
                }
            }
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