#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
#define int long long
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int i=0,num_1=0,num_2=0,num_3=0;
    while(i<n)
    {
        if(a[i]==1)
            num_1++;
        else if(a[i]==2)
            num_2++;
        else if(a[i]==3)
            num_3++;
        i++;
        if(num_1>=num_2+num_3)
        {
            break;
        }

    }
    if (i==n)
    {
        cout<<"NO"<<endl;
        return;
    }
    int _i=i,_num_1=num_1,_num_2=num_2,_num_3=num_3;
    num_1=0,num_2=0,num_3=0;
    while(i<n)
    {
        if(a[i]==1)
            num_1++;
        else if(a[i]==2)
            num_2++;
        else if(a[i]==3)
            num_3++;
        i++;
        if(num_1+num_2>=num_3)
        {
            break;
        }
    }
    if (i!=n)
    {
        cout<<"YES"<<endl;
        return;
    }
    if (_num_1>_num_2+_num_3)
    {
        i=_i+1;
    }
    num_1=0,num_2=0,num_3=0;
    while(i<n)
    {
        if(a[i]==1)
            num_1++;
        else if(a[i]==2)
            num_2++;
        else if(a[i]==3)
            num_3++;
        i++;
        if(num_1+num_2>=num_3)
        {
            break;
        }
    }
    if (i!=n)
    {
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
