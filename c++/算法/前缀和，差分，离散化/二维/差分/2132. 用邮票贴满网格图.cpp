
//https://leetcode.cn/problems/stamping-the-grid/
class Solution
{
public:
    bool possibleToStamp(vector<vector<int> > &grid, int stampHeight, int stampWidth)
    {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int> > preSum(n + 2, vector<int>(m + 2, 0)), sub(
            n + 2, vector<int>(m + 2, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + grid[i - 1][j - 1];
            }
        }
        function < bool(int, int) > check = [&](int x, int y) //1-based
        {
            //以(x,y)为左上角，边长为(stampHeight,stampWidth)的矩形是否满足条件
            return preSum[x + stampHeight - 1][y + stampWidth - 1] - preSum[x - 1][y + stampWidth - 1] - preSum[
                       x + stampHeight - 1][y - 1] + preSum[x - 1][y - 1] == 0;
        };
        function < void(int, int) > set = [&](int x, int y)
        {
            //以(x,y)为左上角，看看能不能放，如果能放就把这个矩形内的格子都标记为1
            if (check(x, y))
            {
                sub[x][y]++;
                sub[x + stampHeight][y]--;
                sub[x][y + stampWidth]--;
                sub[x + stampHeight][y + stampWidth]++;
            }
        };
        for (int i = 1; i <= n +1- stampHeight; i++) //能放就放
        {
            for (int j = 1; j <= m +1- stampWidth; j++)
            {
                set(i, j);
            }
        }
        for (int i = 1; i <= n; i++) //差分数组还原
        {
            for (int j = 1; j <= m; j++)
            {
                sub[i][j] += sub[i - 1][j] + sub[i][j - 1] - sub[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= n; i++) //看看有没有格子是0但是没有被覆盖
        {
            for (int j = 1; j <= m; j++)
            {
                if (grid[i - 1][j - 1] == 0 && sub[i][j] == 0) return false;
            }
        }
        return true;
    };
};
