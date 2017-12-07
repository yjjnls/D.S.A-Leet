/*

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.


*/
#include <common.hpp>
class Solution2
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int len = 0;
        for (int i = 1; i < m + 1; ++i)
        {
            for (int j = 1; j < n + 1; ++j)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[i][j] = std::min(dp[i - 1][j], std::min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    len = std::max(dp[i][j], len);
                }
            }
        }
        return len * len;
    }
};

/*
solution 1 brute force
和01matrix一样，遍历矩阵，遇到一个1就逐步向右边和底边遍历，看是否都是1
如果都是1，那么square的边长+1，否则跳出这个循环

time:O(mn*mn)
space:O(1) 矩阵的存储空间不算

solution 2 dp
dp[i][j]表示右下角坐标为(i-1,j-1)的正方形，其最大边长 1<=i<=m 1<=j<=n
dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1

！！！边界的初始化不好判断，所有dp整个相对于matrix向右下移动一位，相对于72题的话，边界好判断，但是word的下标与dp的下标对应，所以是i<=m
time:O(mn)
space:O(mn)

solution 3 optimized dp
优化存储空间，将dp压缩为一维
dp[i]=min(dp[i−1],dp[i],prev)
prev为原来的dp[i-1][j-1]
dp[i]为原来的dp[i-1][j]
dp[i-1]为原来的dp[i][j-1]

*/

class Solution3
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> dp(n + 1, 0);

        int len = 0;

        for (int i = 1; i < m + 1; ++i)
        {
            int prev = 0;//每一维开始时的prev无法确定，即求matrix[i-1][0]为右下角结点的square大小，这里就暂且将prev设为0（matrix[i-1][0]为0时的默认值），matrix[i-1][0]为1时，下面会将dp[1]设为1
            for (int j = 1; j < n + 1; ++j)
            {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[j] = std::min(prev, std::min(dp[j - 1], dp[j])) + 1;
                    len = std::max(dp[j], len);
                }
                else
                {
                    dp[j] = 0;//这一行不能少，每次新的i行都要讲i-1行的数据给覆盖
                }
                prev = temp;
            }
        }
        return len * len;
    }
};

#ifdef USE_GTEST
TEST(DSA, 221_Maximal_Square)
{
    vector<vector<char>> matrix{{'1', '0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'}};
    Solution2 s1;
    int res = s1.maximalSquare(matrix);
    ASSERT_TRUE(res == 4);
}
#endif