// https://leetcode.cn/problems/longest-well-performing-interval/description/
class Solution
{
public:
    int longestWPI(vector<int> &hours)
    {
        int n = hours.size(), l = 0;
        unordered_map<int, int> mp;
        vector<int> pre_sum(n + 1);
        for (int i = 0; i < n; i++)
        {
            pre_sum[i + 1] = pre_sum[i] + (hours[i] > 8 ? 1 : -1);
            if (mp.find(pre_sum[i]) == mp.end())
                mp[pre_sum[i]] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            if (pre_sum[i]>0)
                l = max(l, i);
            else if (mp.find(pre_sum[i] - 1) != mp.end())
                l = max(l, i - mp[pre_sum[i] - 1]);
        }
        return l;
    }
};
