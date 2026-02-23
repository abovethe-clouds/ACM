// https://leetcode.cn/problems/subarray-sum-equals-k/description/
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> pre_sum_count;
        pre_sum_count[0] = 1; // 初始化前缀和为0的情况

        for (int num: nums)
        {
            sum += num;
            if (pre_sum_count.find(sum - k) != pre_sum_count.end())
            {
                count += pre_sum_count[sum - k];
            }
            pre_sum_count[sum]++;
        }
        return count;
    }
};
