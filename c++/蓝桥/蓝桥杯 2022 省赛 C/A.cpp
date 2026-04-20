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
bool judge(string s)
{
    for (int i=1;i<s.length()-1;i++)
    {
        if (s[i]-1==s[i-1] && s[i]+1==s[i+1])
            return true;
    }
    return false;
}
void solve()
{
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int ans=0;
    for (int i=0;i<12;i++)
    {
        for (int j=1;j<=month[i];j++)
        {
            string s="2022";
            if (i+1<10)
                s+='0';
            s+=to_string(i+1);
            if (j<10)
                s+='0';
            s+=to_string(j);
            if (judge(s))
                ans++;
        }
    }
    cout<<ans<<endl;
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
// #include<iostream>
// using namespace std;
// int main() {
//     string ans [] = {
//         "1478", // 双引号中替换为 A 题的答案
//         "14", // 双引号中替换为 B 题的答案
//     };
//     char T;
//     cin >> T;
//     cout << ans[T - 'A'] << endl;
//     return 0;
// }

