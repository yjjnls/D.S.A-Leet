/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" 
cells are those horizontally or vertically neighboring. The same letter cell may not be 
used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.

click to show hint.

You would need to optimize your backtracking to pass the larger test. 
Could you stop backtracking earlier?

If the current candidate does not exist in all words' prefix, you could 
stop backtracking immediately. What kind of data structure could answer 
such query efficiently? Does a hash table work? Why or why not? How about 
a Trie? If you would like to learn how to implement a basic trie, please 
work on this problem: Implement Trie (Prefix Tree) first.
*/
#include <common.hpp>
class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int row = board.size();
        int col = -1;
        vector<string> res;

        for (int i = 0; i < row; ++i)
        {
            col = board[i].size();
            for (int j = 0; j < col; j++)
            {
                for (int s = 0; s < words.size(); ++s)
                {
                    if (found_dfs(board, i, j, words[s], 0))
                        res.push_back(word[s]);
                }
            }
        }
        return res;
    }
    bool found_dfs(vector<vector<char>> &board, int x, int y, string &word, int pos)
    {
        //recursion termiantor
        if (word[pos] == '\0')
            return true;
        if (x < 0 || y < 0 || x >= board.size() || y >= board[x].size())
            return false;
        if (board[x][y] != word[pos])
            return false;

        //current level processing
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

/*
感觉和79 word search一样，只不过多了几个单词
time:O(m*n*k*s) k是平均字长 s是words个数
*/ 