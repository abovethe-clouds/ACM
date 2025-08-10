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

void solve()
{
    const int N = read();
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++)
        a[i] = read();
    for (int i = 0; i < N; i++)
        b[i] = read();
    if (a[N-1]!=b[N-1])
    {
        cout<<"NO"<<endl;
        return;
    }
    for (int i = 0; i < N-1; i++)
    {
        if ((a[i]^a[i+1])==b[i])
            a[i]=a[i]^a[i+1];
    }
    for (int i = N-2; i >=0; i--)
        if ((a[i]^a[i+1])==b[i])
            a[i]=a[i]^a[i+1];
    for (int i=0;i<N;i++)
        if (a[i]!=b[i])
        {
            cout<<"NO"<<endl;
            return;
        }
    cout<<"YES"<<endl;
}

int main()
{

    int t = read();
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
