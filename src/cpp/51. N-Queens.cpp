/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/
#include <common.hpp>
namespace
{
    class Solution
    {
    public:
        vector<vector<string>> solveNQueens(int n)
        {
            vector<string> nQueens(n, string(n, '.'));
            dfs(nQueens, 0, n);

            return res;
        }

    private:
        void dfs(vector<string> &nQueens, int row, int n)
        {
            //recursion terminator
            if (row == n)//整个棋盘扫描完，row本应该是0 ~ (n-1)
            {
                res.push_back(nQueens);
                return;
            }

            for (int col = 0; col < n; ++col)
            {
                if (is_valid(nQueens, row, col, n))
                {
                    //current level processing
                    nQueens[row][col] = 'Q';
                    //drill down
                    dfs(nQueens, row + 1, n);
                    //reverse status
                    nQueens[row][col] = '.';
                }
            }
        }
        bool is_valid(vector<string> &nQueens, int row, int col, int n)
        {
            //看当前点的上半部分，因为之后的点还没填
            for (int i = 0; i < row; ++i)
            {
                if (nQueens[i][col] == 'Q')
                    return false;
            }

            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            {
                if (nQueens[i][j] == 'Q')
                    return false;
            }

            for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            {
                if (nQueens[i][j] == 'Q')
                    return false;
            }
            return true;
        }
        vector<vector<string>> res;
    };

/*
soulution 1
backtrace或者叫dfs
形式上和37题 解数独 的过程类似
bfs写出来就比较烦，比较傻


*/

#ifdef USE_GTEST
    TEST(DSA, 51_NQueens)
    {
        Solution s;
        vector<vector<string>> res = s.solveNQueens(4);
        vector<vector<string>> result = {{".Q..",
                                          "...Q",
                                          "Q...",
                                          "..Q."},
                                         {"..Q.",
                                          "Q...",
                                          "...Q",
                                          ".Q.."}};
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 4; ++j)
                ASSERT_TRUE(res[i][j].compare(result[i][j]) == 0);
    }
#endif
}