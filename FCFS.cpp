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
struct PCB
{
    char c;
    int ad,ser;
    int over;
    friend istream& operator>>(istream& in, PCB& obj)
    {
        in >> obj.c >> obj.ad >> obj.ser;
        return in;
    }
    friend ostream& operator<<(ostream& out, PCB& obj)
    {
        return out << obj.c << " "  << obj.over<<" "<< obj.over-obj.ad<<" "<<(obj.over-obj.ad)*1.0/obj.ser<<endl;
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<PCB> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), [](PCB x, PCB y)
    {
        return x.ad < y.ad;
    });
    int begin=a[0].ad;
    for (int i=0;i<n;i++)
    {
        begin = max(begin, a[i].ad);
        a[i].over = begin + a[i].ser;
        begin=a[i].over;
    }
    for (int i=0;i<n;i++)
        cout<<a[i];
    double zhou=0,dai=0;
    for (int i=0;i<n;i++)
    {
        cout<<a[i];
        zhou+=a[i].over-a[i].ad;
        double x=(a[i].over-a[i].ad)*1.0/a[i].ser;
        dai+=x;
    }
    zhou/=n;
    dai/=n;
    cout<<zhou<<" "<<dai;

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
    while (t--)
        solve();
    return 0;
}
