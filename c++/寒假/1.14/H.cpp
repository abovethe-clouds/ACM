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
map<string,int> people;
int n,m,l;
void solve()
{
    while(cin>>n>>m>>l)
    {
        people.clear();
        for (int i = 0; i < n; i++)//v
        {
            string s;
            cin>>s;
            people[s]=2333;
        }
        vector<string> oh;
        for (int i = 0; i < m; i++)//x
        {
            string s;
            cin>>s;
            oh.push_back(s);
            if(people.find(s)!=people.end())
            {
                people[s]=1111;
            }
        }
        for (int i = 0; i < l; i++)//v
        {
            string s;
            cin>>s;
            if(people.find(s)!=people.end())
            {
                people[s]=2333;
            }
        }
        bool yahu=0;
        for(auto &i:oh)
        {
            if(people[i]==1111)
            {
                cout<<i<<" ";
                yahu=1;
            }    
        }
        if(yahu==0)
        {
            cout<<"No enemy spy";
        }
        cout<<endl;
    }
    return;
    
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