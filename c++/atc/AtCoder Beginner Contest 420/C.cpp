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


void solve()
{
    ll N , Q ;
    cin >> N >> Q;
    vector<ll> A(N), B(N),minn(N);
    ll sum=0;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    for (int i = 0; i < N; i++)
    {
        minn[i]=min(A[i],B[i]);
        sum+=minn[i];
    }
    for (int i = 0; i < Q; i++)
    {
        char ch;
        int xi,vi;
        cin >> ch >> xi >> vi;
        xi--;
        if (ch == 'A')
        {
            sum-=minn[xi];
            A[xi]=vi;
            minn[xi]=min(A[xi],B[xi]);
            sum+=minn[xi];

        }
        else
        {
            sum-=minn[xi];
            B[xi]=vi;
            minn[xi]=min(A[xi],B[xi]);
            sum+=minn[xi];
        }
        cout << sum << "\n";
    }


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
} //
// Created by Administrator on 2025/8/24.
//
