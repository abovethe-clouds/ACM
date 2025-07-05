#include <bits/stdc++.h>
using namespace std;
int dp[200004], N, L, R, a[200004], max0 = -1e9;
int main()
{
    cin >> N >> L >> R;
    for (int i = 0; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++)
        dp[i] = -1e9;
    for (int i = L; i <= N; i++)
    {
        int ans = -1e9;
        for (int j = L; j <= R && i - j >= 0; j++)
            if (dp[i - j] != -1e9)
                ans = max(dp[i - j], ans);
        if (ans == -1e9)
        {
            dp[i] == -1e9;
            continue;
        }
        dp[i] = a[i] + ans;
        if (i + R > N)
            max0 = max(max0, dp[i]);
    }
    cout << max0;
    return 0;
}