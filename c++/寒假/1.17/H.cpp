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
char a[15];
int l,c;
bool judge(string s)
{
    int y=0,f=0;
    int q=s.length();
    for (int i = 0; i < q; i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            y++;
        else
            f++;
    }
    if(y>0&&f>1)
        return true;
    else
        return false;
    
}
void dfs(int x,string s,int p)
{
    if(p==l)
    {
        if(judge(s))
            cout<<s<<endl;
        return;
    }
    if(x==c)
        return;
    string y=s+a[x];
    dfs(x+1,y,p+1);
    dfs(x+1,s,p);
    
    return;

}
void solve()
{
    cin>>l>>c;
    for (int i = 0; i < c; i++)
    {
        cin>>a[i];
    }
    sort(a,a+c);
    dfs(0,"",0);
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