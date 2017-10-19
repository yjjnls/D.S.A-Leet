/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
#include <common.hpp>
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int row = board.size();
        int col = -1;
        for (int i = 0; i < row; ++i)
        {
            col = board[i].size();
            for (int j = 0; j < col; j++)
            {
                if (found_dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }

    bool found_dfs(vector<vector<char>> &board, int x, int y, string &word, int pos)
    {
        //recursion terminator
        if (word[pos] == '\0')
            return true;
        if (x < 0 || y < 0 || x == board.size() || y == board[x].size())
            return false;
        if (board[x][y] != word[pos])
            return false;

        //current level processing
        //因为ascii码从0-127，抑或上256，就把该字母变成非字母
        //但是这里对c++不管用
        char tmp = board[x][y];
        board[x][y] = -1;

        //drill down
        bool res = found_dfs(board, x - 1, y, word, pos + 1) ||
                   found_dfs(board, x + 1, y, word, pos + 1) ||
                   found_dfs(board, x, y - 1, word, pos + 1) ||
                   found_dfs(board, x, y + 1, word, pos + 1);

        //reverse current level status
        board[x][y] = tmp;

        return res;
    }
};

//time:O(M*N*K)
//k为单词平均长度

//貌似bfs也可以做，而且更好？