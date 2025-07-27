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

int read()
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    {  
        if (ch == '-') w = -1;        
        ch = getchar();               
    }
    while (ch >= '0' && ch <= '9')
    {  
        x = x * 10 + (ch - '0');
        ch = getchar();  
    }
    return x * w; 
}

string ss()
{
    uniform_int_distribution<int> list(1, 999), list1(1, 4), list2(11, 99),list3(100, 999),list4(2,9);
    random_device re;
    int ch=(list1(re));
    int a, b;
    switch (ch)
    {
    case 1:
        a = list(re);
        b = list(re);
        return to_string(a) + '+' + to_string(b) + "=";
        break;
    case 2:
        a = list(re);
        b = list(re);
        if (a < b)
            swap(a, b);
        return to_string(a) + '-' + to_string(b) + "=";
        break;
    case 3:
        a = list2(re);
        b = list2(re);
        return to_string(a) + '*' + to_string(b) + "=";
        break;
    case 4:
        a = list3(re);
        b = list4(re);
        return to_string(a) + "/" + to_string(b) + "=";
        break;
    }
}
void solve()
{
    for (int i = 1; i <= 42*7*30; i++)
    {
        cout << left << setw(13) << ss();
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE 
        freopen("test.in", "r", stdin);
       freopen("test.out", "w", stdout);
    #endif
    int t = 1;
    //cin >> t;
    while(t--)
        solve();

    return 0;
}