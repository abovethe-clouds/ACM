#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
int n; 
bool judge(string s) 
{ 
    return string(s.rbegin(), s.rend()) == s; 
}
string change(ll x)
{
    if (x == 0)
        return "0";
    string ans;
    while (x)
    {
        ans.push_back('0' + (x % n));
        x /= n;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
ll pow10_by_digits(ll x)
{
    ll p = 1;
    while (x)
    {
        p *= 10;
        x /= 10;
    }
    return p;
}
ll makeOddReverseString(ll x)
{
    ll re = x / 10, end = 0, tmp = re;
    while (tmp)
    {
        end = end * 10 + tmp % 10;
        tmp /= 10;
    }
    return x * pow10_by_digits(re) + end;
}
ll makeEvenReverseString(ll x)
{
    ll end = 0, tmp = x;
    while (tmp)
    {
        end = end * 10 + tmp % 10;
        tmp /= 10;
    }
    return x * pow10_by_digits(x) + end;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;          
    cin >> n >> N; 
    ll ans = 0;
    for (int d = 1; d <= 9 && d <= N; ++d)
    {
        string s = change(d);
        if (judge(s))
            ans += d;
    }
    int lenN = to_string(N).size();
    ll lim = 1;
    for (int i = 0; i < (lenN + 1) / 2; ++i)
        lim *= 10; 
    for (ll p = 1; p < lim; ++p)
    {
        ll even = makeEvenReverseString(p);
        if (even > N)
            break; 
        if (judge(change(even)))
            ans += even;
        for (int mid = 0; mid <= 9; ++mid)
        {
            ll odd = makeOddReverseString(p * 10 + mid);
            if (odd > N)
                break;
            if (judge(change(odd)))
                ans += odd;
        }
    }
    cout << ans << '\n';
    return 0;
}
