#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"   
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131, maxn=1e6+5;
char a[maxn],b[maxn];
int kmp[maxn];
void solve()
{
    cin>>a+1;
    cin>>b+1;
    int l1=strlen(a+1);
    int l2=strlen(b+1);
    int j=0;
    for(int i=2;i<=l2;i++)
    {
        while(j&&b[i]!=b[j+1])
            j=kmp[j];
        if(b[i]==b[j+1])
            j++;
        kmp[i]=j;
    }
    j=0;
    for (int i = 1; i <= l1; i++)
    {
        while(j&&a[i]!=b[j+1])
            j=kmp[j];
        if(a[i]==b[j+1])
            j++;
        if(j==l2)
        {
            cout<<i-l2+1<<endl;
            j=kmp[j];
        }
    }
    
    for (int i = 1; i <= l2; i++)
    {
        cout<<kmp[i]<<" ";
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
