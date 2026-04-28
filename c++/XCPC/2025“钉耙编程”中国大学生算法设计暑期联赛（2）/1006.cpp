#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int lowbit(int n)
{
    return n & -n;
}
int n;
int b[1000001];
void tian(int m)
{
    while (m <= n)
    {
        //	cout << m << endl;
        b[m]++;
        m += lowbit(m);
    }
}
int get(int m)
{
    int sum = 0;
    while (m > 0)
    {
        sum += b[m];
        m -= lowbit(m);
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false); // 关闭同步
    cin.tie(nullptr);
    long long t;
    cin >> t;
    int a[1000001];
    map<int, int> mp;
    while (t--)
    {
        cin >> n;
        int sum[1000001] = {0};
        for (int i = 0; i < 1000001; i++)
            b[i] = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i], mp[a[i]] = i;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = n; i > 0; i--)
        {
            sum[a[i]] += i - 1 + get(mp[a[i]]);
            tian(mp[a[i]]);
        }
        for (int i = 1; i <= n; i++)
        {
            cout << sum[i] << " ";
        }
        cout << endl;
    }
    return 0;
}