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

void print(vector<int> v)
{
    int n = v.size();
    cout << v[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << v[i];
    }
    cout << endl;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    stack<int> st;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (ans.empty())
        {
            if (st.empty())
            {
                ans.push_back(v[i]);
            }
            else
            {
                ans.push_back(st.top());
                st.pop();
                while (!st.empty() && st.top() <= ans.back())
                {
                    ans.push_back(st.top());
                    st.pop();
                    if (ans.size() == k)
                    {
                        print(ans);
                        ans.clear();
                        cout<<endl;
                    }
                }
                st.push(v[i]);
                while (!st.empty() && st.top() <= ans.back())
                {
                    ans.push_back(st.top());
                    st.pop();
                    if (ans.size() == k)
                    {
                        print(ans);
                        ans.clear();
                        cout<<endl;
                    }
                }
            }
            continue;
        }
        while (!st.empty() && st.top() <= ans.back())
        {
            ans.push_back(st.top());
            st.pop();
            if (ans.size() == k)
            {
                print(ans);
                ans.clear();
            }
        }
        st.push(v[i]);
        while (!st.empty() && st.top() <= ans.back())
        {
            ans.push_back(st.top());
            st.pop();
            if (ans.size() == k)
            {
                print(ans);
                ans.clear();
            }
        }
        if (st.size() == m)
        {
            print(ans);
            ans.clear();
        }
    }
    while (!st.empty() )
    {
        if (ans.empty())
        {
            ans.push_back(st.top());
            st.pop();
            continue;
        }
        if (st.top()<=ans.back())
        {
            ans.push_back(st.top());
            st.pop();
            if (ans.size() == k)
            {
                print(ans);
                ans.clear();
            }
        }

    }
    print(ans);
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
