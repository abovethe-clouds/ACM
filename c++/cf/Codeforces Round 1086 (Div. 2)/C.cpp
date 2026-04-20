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
    int c[n], p[n];
    for(int i = 0;i < n;i++)cin >> c[i] >> p[i];
    double sum = 0;
    for(int i = n - 1;i >= 0;i--){
        double d = c[i] + sum * (100 - p[i]) / 100;
        sum = max(sum, d);
    }
    printf("%.8lf\n", sum);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--)que();
    return 0;
}