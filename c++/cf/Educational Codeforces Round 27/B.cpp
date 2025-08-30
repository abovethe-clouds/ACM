#include<bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, P = 131;
int sum(int a)
{
    string s = to_string(a);
    int sum=0;
    for (int i = 0; i < s.length(); i++)
    {
        sum+=s[i]-'0';
    }
    return sum;
}
string to_6string(int a)
{
    string s = to_string(a);
    if (s.length()!=6)
        return string(6-s.length(), '0')+s;
    else
        return s;
}
void solve()
{
    string s;
    cin >> s;
    int minn=INT_MAX;
    for (int i=0;i<1e6;i++)
    {
        int front=i/1000;
        int back=i%1000;
        if (sum(front)==sum(back))
        {
            int cnt=0;
            string s1=to_6string(i);
            for (int j=0;j<6;j++)
            {
                if (s1[j]!=s[j])
                    cnt++;
            }
            minn=min(minn,cnt);
        }
    }
    cout<<minn<<endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}//
// Created by Administrator on 2025/8/28.
//