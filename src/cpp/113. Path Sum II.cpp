/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <common.hpp>
class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        dfs(root, sum, vector<int>{});
        return res;
    }
    void dfs(TreeNode *root, int sum, vector<int> path)
    {
        // recursion terminator
        if (root == NULL)
            return;
        // current level processing
        path.push_back(root->val);
        if ((sum - root->val) == 0 &&
            root->left == NULL &&
            root->right == NULL)
        {
            res.push_back(path);
            return;
        }
        // drill down
        dfs(root->left, sum - root->val, path);
        dfs(root->right, sum - root->val, path);
    }

private:
    vector<vector<int>> res;
};