// https://leetcode.cn/problems/range-sum-query-immutable/description/ 前缀和板子
class NumArray
{
public:
    vector<int> pre_sum;

    NumArray(vector<int> &nums)
    {
        int n = nums.size();
        pre_sum.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }


    }
    int sumRange(int left, int right)
    {
        return pre_sum[right + 1] - pre_sum[left];
    }
};
