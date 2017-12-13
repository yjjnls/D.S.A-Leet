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
还可以进一步优化就是用3个vector<bool>，直接通过数组的随机访问来判断，这样更加快

solution 3 best optimized （bitwise）
1.for (int col = 0; col < n; ++col)这一步是每次都会遍历col从0到n-1，然后通过上述结构判重
能否直接使用之前没有使用过的col？
2.solution 2里面的优化通过数组的随机访问来判重，将vector<bool>优化为int，通过位运算来操作

solution 2中col有n个 diag1 diag2有 2n-1个
而solution3中col diag1 diag2仅表示上一层的状态
        X
      O O O
上一层选了X这个位置，下一层就不能放三个O的位置

*/
    using std::unordered_set;
    class Solution2
    {
    public:
        int totalNQueens(int n)
        {
            res = 0;
            dfs(0, n);

            return res;
        }

    private:
        void dfs(int row, int n)
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
                dfs(row + 1, n);

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
            res = 0;
            dfs(0, n, 0, 0, 0);

            return res;
        }

    private:
        void dfs(int row, int n, int col, int diag1, int diag2)
        {
            //recursion terminator
            if (row == n)//整个棋盘扫描完，row本应该是0 ~ (n-1)
            {
                res++;
                return;
            }
            // 获取空的位置
            // col|diag1|diag2表示空位，表示可以放皇后的位置（bit为0的位），然后取反，bit为1就表示是有效位置
            // 但是int有32位,col diag1 diag2都只用到了n位,剩下的高位其实没有用,上一步取反后反而会变成1,所以这里要将其高位置1 -> & ((1 << n) - 1)
            int bits = (~(col | diag1 | diag2)) & ((1 << n) - 1);
            while (bits)
            {
                // 这里仅选取有效位置进行dfs
                // 获取最低位的1
                int p = bits & (-bits);
                // 设置当前选取的位置bit为1，之前选过的位置也会保留在里面继续传递下去
                dfs(row + 1, n, col | p, (diag1 | p) << 1, (diag2 | p) >> 1);
                // 取出最低位的1
                bits = bits & (bits - 1);
            }
        }

        int res;
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