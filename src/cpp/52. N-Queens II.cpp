/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/
#include <common.hpp>
namespace
{

    class Solution
    {
    public:
        int totalNQueens(int n)
        {
            res = 0;
            vector<string> nQueens(n, string(n, '.'));
            dfs(nQueens, 0, n);

            return res;
        }

    private:
        void dfs(vector<string> nQueens, int row, int n)
        {
            //recursion terminator
            if (row == n)//整个棋盘扫描完，row本应该是0 ~ (n-1)
            {
                res++;
                return;
            }

            for (int col = 0; col < n; ++col)
            {
                //这个is_valid相当于剪枝，无效的分支直接就不继续下去了
                //如果不剪枝，那么每次都要把整个棋盘全部填完
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
        bool is_valid(vector<string> nQueens, int row, int col, int n)
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
        int res;
    };
//还是用dfs



#ifdef USE_GTEST
    TEST(DSA, 52_NQueensII)
    {
        Solution s;
        int res = s.totalNQueens(5);
        ASSERT_TRUE(res == 4);
    }
#endif
}