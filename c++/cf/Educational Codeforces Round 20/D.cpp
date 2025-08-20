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
string s;
int n;
vector<int> lenWord;
bool check(int x)
{
    int line=1,len=0;
    for(int i=0;i<lenWord.size();i++)
    {
        if (len+lenWord[i]<=x)
            len+=lenWord[i];
        else
        {
            line++;
            len=lenWord[i];
        }
    }
    if (line>n)
        return false;
    else
        return true;
}
void solve()
{
    cin>>n;
    getline(cin,s);
    getline(cin, s);
    int len=0;
    for(int i=0;i<s.length();i++)
    {
        len++;
        if(s[i]==' '||s[i]=='-')
        {
            lenWord.push_back(len);
            len=0;
        }
    }
    lenWord.push_back(len);
    int l=*max_element(lenWord.begin(), lenWord.end());
    int r=s.length();
    while (l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
            r=mid-1;
        else
            l=mid+1;
    }
    cout<<l<<endl;
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
// Created by Administrator on 25-8-19.
//
