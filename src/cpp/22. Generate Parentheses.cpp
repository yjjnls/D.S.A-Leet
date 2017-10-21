/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/
#include <common.hpp>
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        _dfs(string(""), n, 0);
        return res;
    }
    void _dfs(string s, int left, int right)
    {
        // recursion terminator
        if (left == 0 && right == 0)
        {
            res.push_back(s);
            return;
        }
        // process current level + drill down
        if (right > 0)
            _dfs(s + ")", left, right - 1);
        if (left > 0)
            _dfs(s + "(", left - 1, right + 1);
    }

private:
    vector<string> res;
};

//这和dfs有什么关系？

/*
1. dfs 
用最普通的dfs，然后在terminator时每个都验证valid
这样复杂度为O(2^n)

可以在中间就判断，发现错误就把这个分支剪掉
*/