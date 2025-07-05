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
string s;
int n,k;
bool panling()
{
    for (int i = 0; i < n; i++)
    {
        if(s[i]!='0')
            return false;
    }
    return true; 
    
}
int jisuan(int x,int y){return x*y;}
bool fengge(int quan)
{
    int zero_num=0,one_num=0,cishu=1;
    for(int i=0;cishu<=k&&i<n;i++)
    {
        if(s[i]=='0')
            zero_num++;
        else
            one_num++;
        if(jisuan(zero_num,one_num)>=quan)
        {
            i++;
            cishu++;
            if(s[i]=='0')
            {
               zero_num=1;
               one_num=0 ;
			}    
			else
            {
                one_num=1;
                zero_num=0;
			}    
        }
        if(cishu>k)
        {
            return 0;
        }
    }
    return 1;                   //原来的大了
}
void solve()
{
    cin>>n>>k>>s;
    if(panling())
    {
        cout<<0;
        return;
    }
    int l=0,r=n,mid=l+(r-l)/2;
    while(l+1>=r)
    {
        if(fengge(mid)==0)
        {
            l=mid+1;
            mid=l+(r-l)/2;
        }
        else
        {
            r=mid;
            mid=l+(r-l)/2;
        }
    }
    //if(l+1==r)
    	
    cout<<mid;
    
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