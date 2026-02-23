//https://leetcode.cn/problems/make-sum-divisible-by-p/
class Solution {
public:
    int minSubarray(vector<int>& nums, int p)
    {
        int n = nums.size();
        int l=INT_MAX;
        unordered_map<int, int> mp;
        int mod = 0;
        for (int i = 0; i < n; i++)
        {
            mod = (mod + nums[i]) % p;
        }
        if (mod == 0)
            return 0;
        mp[0] = -1;
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            cur = (cur + nums[i]) % p;
            int find = cur >= mod ? (cur - mod) : (cur + p - mod);
            if (mp.find(find) != mp.end())
                l = min(l, i - mp[find]);
            mp[cur] = i;
        }
        return (l==n?-1:l);
    }
};