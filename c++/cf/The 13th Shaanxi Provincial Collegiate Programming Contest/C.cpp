#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define inf LONG_LONG_MAX
//#define inf INT_MAX
#define int long long
#define mod 998244353
void que(){
    int a, b;
    cin >> a >> b;
    while(b != 1){
        int k = gcd(a, b);
        if(k == 1){
            cout << b << endl;
            return;
        }
        b /= k;
    }
    cout << -1 << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--)que();
    return 0;
}