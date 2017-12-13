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
        void dfs(vector<string> &nQueens, int row, int n)
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
        int res;
    };
    //还是用dfs
    /*
solution 2 optimized
优化的本质在于is_valid这一步，这里需要判断的是当前棋子的【上半部分】是否有皇后会攻击它
solution 1用的是遍历棋盘，这是最慢的，这里对应的current level processing是将当前棋子置为Q用于下一层的棋盘遍历

优化的方法就是用三个set（一个垂直的和两个对角线）来保存当前棋子的位置，在下一层中，通过hashset来判断是否已经访问过了
还可以进一步优化就是用3个vector<bool>，直接通过数组的随机访问来判断

*/
    using std::unordered_set;
    class Solution2
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
        void dfs(vector<string> &nQueens, int row, int n)
        {
            //recursion terminator
            if (row == n)//整个棋盘扫描完，row本应该是0 ~ (n-1)
            {
                res++;
                return;
            }
            for (int col = 0; col < n; ++col)
            {
                //剪枝
                if (hash_col.count(col) != 0)
                    continue;
                if (hash_diag1.count(row - col) != 0)
                    continue;
                if (hash_diag2.count(row + col) != 0)
                    continue;

                //current level processing
                hash_col.insert(col);
                hash_diag1.insert(row - col);
                hash_diag2.insert(row + col);

                //drill down
                dfs(nQueens, row + 1, n);

                //reverse status
                hash_col.erase(col);
                hash_diag1.erase(row - col);
                hash_diag2.erase(row + col);
            }
        }
        int res;
        unordered_set<int> hash_col;
        unordered_set<int> hash_diag1;
        unordered_set<int> hash_diag2;
    };


    class Solution3
    {
    public:
        int totalNQueens(int n)
        {
        }
    };

#ifdef USE_GTEST
    TEST(DSA, 52_NQueensII)
    {
        Solution s;
        int res = s.totalNQueens(5);
        ASSERT_TRUE(res == 10);
    }
#endif
}