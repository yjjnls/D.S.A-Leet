/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
[[1,3,1],
 [1,5,1],
 [4,2,1]]
Given the above grid map, return 7. Because the path 1→3→1→1→1 minimizes the sum.
*/
#include <common.hpp>
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        //处理边界
        for (int i = 1; i < n; ++i)
            grid[0][i] += grid[0][i - 1];

        for (int i = 1; i < m; ++i)
            grid[i][0] += grid[i - 1][0];

        //递推
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);

        return grid[m - 1][n - 1];
    }
};
//DP
//time:O(n)
#ifdef USE_GTEST
TEST(DSA, 64_minPathSum)
{
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    Solution s;
    int res = s.minPathSum(grid);
    ASSERT_TRUE(res == 7);
}
#endif