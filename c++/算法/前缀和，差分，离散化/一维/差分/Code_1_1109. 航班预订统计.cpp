//https://leetcode.cn/problems/corporate-flight-bookings/description/
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
    {
        vector<int> res(n, 0);
        for (auto& booking : bookings)
        {
            int start = booking[0] - 1;
            int end = booking[1] - 1;
            int seats = booking[2];
            res[start] += seats;
            if (end + 1 < n)
            {
                res[end + 1] -= seats;
            }
        }
        for (int i = 1; i < n; ++i)
        {
            res[i] += res[i - 1];
        }
        return res;
    }
};
