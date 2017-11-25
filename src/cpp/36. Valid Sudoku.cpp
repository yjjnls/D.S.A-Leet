#include <common.hpp>
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool row_used[9][9] = {false};
        bool col_used[9][9] = {false};
        bool sub_used[9][9] = {false};
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;

                    if (row_used[i][num] || col_used[j][num] || sub_used[k][num])
                        return false;

                    row_used[i][num] = true;
                    col_used[j][num] = true;
                    sub_used[k][num] = true;
                }
            }
        }
        return true;
    }
};

/*
数独的格子一定小于等于9*9，因为每一行每一列中1-9只能出现一次。
子方阵一共有9个
*/