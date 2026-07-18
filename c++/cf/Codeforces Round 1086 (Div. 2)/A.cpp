#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define inf LONG_LONG_MAX
//#define inf INT_MAX
#define int long long
#define mod 998244353
void que(){
    int n;
    cin >> n;
    map<int, int> mp;
    for(int i = 0;i < n;i++){
        for(int u = 0;u < n;u++){
            int d;
            cin >> d;
            mp[d]++;
        }
    }
    int mx = 0;
    for(auto [a, b] : mp)mx = max(mx, b);
    if(mx <= n * (n - 1))cout << "YES\n";
    else cout << "NO\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--)que();
    return 0;
}