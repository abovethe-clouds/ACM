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
map<string,int> stu;
void solve()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int op,soc;
        string s;
        cin>>op;
        switch (op)
        {
        case 1:
            cin>>s>>soc;
            stu[s]=soc;
            cout<<"OK"<<endl;
            break;
        case 2:
            cin>>s;
            if(stu.find(s)!=stu.end())
                cout<<stu[s]<<endl;
            else
                cout<<"Not found"<<endl;
            break;
        case 3:
            cin>>s;
            if(stu.find(s)!=stu.end())
            {
                cout<<"Deleted successfully"<<endl;
                stu.erase(s);
            }
                
            else
            {
                
                cout<<"Not found"<<endl;
            }
            
            break;
        default:
            cout<<stu.size()<<endl;
            break;
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