#include <bits/stdc++.h>
using namespace std;
#define int long long

void que()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), da(n + 1);
    //  priority_queue<pair<int,int>> qe;
    set<int> st = {0, n + 1};
    for (int i = 1; i <= n; i++)
    {
        int d;
        cin >> d;
        a[d] = i;
    }
    int sum = 0;
    for (int i = n; i >= 1; i--)
    {
        auto rr = st.upper_bound(a[i]);
        int r = *rr;
        rr--;
        int l = *rr;
        r = r - a[i];
        l = a[i] - l;
        da[a[i]] = (n - a[i] + 1) * l + (a[i]) * r - l * r;
        st.insert(a[i]);
    }
    for (int i = 1; i <= n; i++)cout << da[i] << " ";
    cout << endl;
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)que();
    return 0;
}
