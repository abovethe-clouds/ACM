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
int n;
struct student
{
    string n;
    int m,d;
};
bool cmp(student x,student y)
{
    if(x.m!=y.m)
        return x.m<y.m;
    if(x.d!=y.d)
        return x.d<y.d;
    if((x.n.length())!=(y.n.length()))
        return x.n.length()<y.n.length() ;  
    return x.n<y.n;
}
void solve()
{
    student a[180];
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i].n>>a[i].m>>a[i].d;
    }
    sort(a,a+n,cmp);
    bool flag=0,ci=0;
    student q=a[0];
    for (int i = 1; i < n; i++)
    {
        if(a[i].m==q.m&&a[i].d==q.d&&flag==0)
        {
            if(ci==1)
                cout<<endl<<q.m<<" "<<q.d<<" "<<q.n<<" "<<a[i].n<<" ";
            else
                cout<<q.m<<" "<<q.d<<" "<<q.n<<" "<<a[i].n<<" ";
            flag=1;ci=1;
        }
        else
        {
            if(a[i].m==q.m&&a[i].d==q.d&&flag==1)
                cout<<a[i].n<<" ";
            else
            {
                q=a[i];
                flag=0;
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