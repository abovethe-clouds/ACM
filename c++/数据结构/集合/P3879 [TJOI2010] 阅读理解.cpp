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
map<string,set<int>> q;
void solve()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin>>p;
        for (int j = 0; j < p; j++)
        {
            string s;
            cin>>s;
            q[s].insert(i);
        }
    }
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        if(q[s].size()!=0)
        {
            vector<int> a;
            for (auto i:q[s])
            {
                a.push_back(i);
            }
            sort(a.begin(),a.end());
            for (auto i:a)
            {
                cout<<i+1<<" ";
            }
        }
        cout<<endl;
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