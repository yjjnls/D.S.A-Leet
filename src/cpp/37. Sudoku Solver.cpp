#include <common.hpp>
class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        _solveSudoku(board, 0, 0);
    }

private:
    bool _solveSudoku(vector<vector<char>> &board, int i, int j)
    {
        //terminator
        //逐行填写
        if (i == 9)
            return true;
        if (j == 9)
            //下一行
            return _solveSudoku(board, i + 1, 0);
        if (board[i][j] != '.')
            //下一个
            return _solveSudoku(board, i, j + 1);
        // c从1-9，要注意<=9
        for (char c = '1'; c <= '9'; ++c)
        {
            if (is_valid(board, i, j, c))
            {
                //current level processing
                board[i][j] = c;
                //drill down
                // 如果数字填对那就不用还原
                if (_solveSudoku(board, i, j + 1))
                    return true;
                //reserve status
                board[i][j] = '.';
            }
        }
        return false;
    }
    bool is_valid(vector<vector<char>> &board, int i, int j, char val)
    {
        for (int x = 0; x < 9; ++x)
        {
            if (board[i][x] == val)
                return false;
        }
        for (int y = 0; y < 9; ++y)
        {
            if (board[y][j] == val)
                return false;
        }
        int row = i / 3 * 3;
        int col = j / 3 * 3;
        for (int x = 0; x < 3; ++x)
        {
            for (int y = 0; y < 3; ++y)
            {
                if (board[row + x][col + y] == val)
                    return false;
            }
        }
        return true;
    }
};

/*
可以叫DFS，也可以交贪心，回溯
只不过这里不是树的结构，每次都有1-9，9个分支

time:(9^m) m个空格

可以优化！！！！！！！！！！！！！
*/