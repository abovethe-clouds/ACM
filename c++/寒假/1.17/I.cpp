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
bool cmp(pii a,pii b)
{
    return a.second>b.second;
}
void solve()
{
    vector<pii> a;
    a.clear();
    int n,t;
    cin>>n>>t;
    for (int i = 0; i < n; i++)
    {
        int t1;
        cin>>t1;
        a.push_back(make_pair(t1,0));
    }
    for(auto &i:a)
    {
        int q;
        cin>>q;
        i.second=q;
    }
    sort(a.begin(),a.end());
    int t3=t,sumA=0,sumB=0;
    for (int i = 0; i < n; i++)
    {
        if(t3<a[i].first)
            break;
        t3-=a[i].first;
        sumA+=a[i].second;
    }
    sort(a.begin(),a.end(),cmp);
    for (int i = 0; i < n; i++)
    {
        if(t<a[i].first)
            break;
        t-=a[i].first;
        sumB+=a[i].second;
    }
    if(sumA>sumB)
        cout<<"A"<<endl;
    if(sumA<sumB)
        cout<<"B"<<endl;
    if(sumA==sumB)
        cout<<"SAME"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t --)
        solve();

    return 0;
}