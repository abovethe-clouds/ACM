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
int n,cnt=0;
vector<int> a;
void solve()
{
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int ss;
        cin>>ss;
		a.push_back(ss);
    }
    sort(a.begin(),a.end());
    for (int i = 0; i < n-2; i++)
    {
        int j=i+1,k=i+2;
        for (; j < n-1; j++)
        {
            while(k<n&&a[i]+a[j]>a[k])
            {
                k++;
			}   
            if(a[i]+a[j]>a[k-1]&&k-1!=j)
				cnt+=(k-j-1);
        }
        
    }
    cout<<cnt;
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