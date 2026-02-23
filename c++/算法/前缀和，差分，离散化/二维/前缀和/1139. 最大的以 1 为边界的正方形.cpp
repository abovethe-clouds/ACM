#include <vector>

//https://leetcode.cn/problems/largest-1-bordered-square/description/
class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid)
    {
        vector<vector<int>> down(grid.size()+1, vector<int>(grid[0].size()+1, 0));//down[i][j]表示以(i,j)为下边界的1的个数
        vector<vector<int>> right(grid.size()+1, vector<int>(grid[0].size()+1, 0));//right[i][j]表示以(i,j)为右边界的1的个数
        for (int i=0; i<grid.size(); i++)
        {
            for (int j=0; j<grid[0].size(); j++)
            {
                down[i+1][j+1]=down[i][j+1]+grid[i][j];
                right[i+1][j+1]=right[i+1][j]+grid[i][j];
            }
        }
        function<bool(int,int,int)> check=[&](int x,int y,int d)
        {
            //以(x,y)为z左上角，边长为d的正方形是否满足条件
            return  down[x+d-1][y]-down[x-1][y]==d&&
                    right[x][y+d-1]-right[x][y-1]==d&&
                    down[x+d-1][y+d-1]-down[x-1][y+d-1]==d&&
                    right[x+d-1][y+d-1]-right[x+d-1][y-1]==d;
        };
        int ans=0;
        for (int i=1; i<=grid.size(); i++)
        {
            for (int j=1; j<=grid[0].size(); j++)
            {
                for (int d=min(grid.size()-i+1,grid[0].size()-j+1); d>ans; d--)
                {
                    if (check(i,j,d))
                    {
                        ans=d;
                        break;
                    }
                }
            }
        }
        return ans*ans;
    }
};