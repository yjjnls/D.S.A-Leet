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
                        res.push_back(words[s]);
                }
            }
        }
        std::sort(res.begin(), res.end());
        vector<string>::iterator end_unique = std::unique(res.begin(), res.end());
        res.erase(end_unique, res.end());
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
!!!这个速度相当慢！！！！
*/

//bfs会比较麻烦，状态不能连续记录

/*solution 2 
思路和word search一样，也是用回溯或者说dfs，但是word search只有一个单词查询
而这里有几个单词一起查询，最简单的就是像上面那样那样，再加一层循环。这样效率很低

另一种优化思路就是用trie将所有单词存起来，然后只在这个trie里面查询就可以，这样复杂度还是O(m*n*k)
*/

class Solution
{
    struct Trie
    {
        string word;//is a word stops here
        Trie *next[26];

        Trie()
        {
            std::fill_n(next, 26, nullptr);//这里用NULL会报错
        }
        ~Trie()
        {
            for (int i = 0; i < 26; ++i)
            {
                if (next[i] != NULL)
                {
                    delete next[i];
                    next[i] = NULL;
                }
            }
        }
    };
    Trie *BuildTrie(vector<string> &words)
    {
        Trie *root = new Trie();
        for (string &word : words)
        {
            Trie *p = root;
            for (int i = 0; i < word.size(); ++i)
            {
                int idx = word[i] - 'a';
                if (p->next[idx] == NULL)
                    p->next[idx] = new Trie();
                p = p->next[idx];
            }
            p->word = word;
        }
        return root;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie *root = BuildTrie(words);

        int row = board.size();
        int col = -1;

        for (int i = 0; i < row; ++i)
        {
            col = board[i].size();
            for (int j = 0; j < col; j++)
            {
                _dfs(board, i, j, root);
            }
        }
        return res;
    }
    void _dfs(vector<vector<char>> &board, int x, int y, Trie *p)
    {
        char c = board[x][y];
        if (c == '#' || p->next[c - 'a'] == NULL)
            return;

        // current level processing
        p = p->next[c - 'a'];
        if (!p->word.empty())
        {
            res.push_back(p->word);
            p->word.clear();//de-duplicate
        }
        board[x][y] = '#';

        // drill down
        if (x > 0)
            _dfs(board, x - 1, y, p);
        if (y > 0)
            _dfs(board, x, y - 1, p);
        if (x < board.size() - 1)
            _dfs(board, x + 1, y, p);
        if (y < board[0].size() - 1)
            _dfs(board, x, y + 1, p);

        //reverse status
        board[x][y] = c;
    }

private:
    vector<string> res;
};