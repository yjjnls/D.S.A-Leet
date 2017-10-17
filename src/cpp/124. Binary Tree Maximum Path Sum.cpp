/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes 
from some starting node to any node in the tree along the 
parent-child connections. The path must contain at least one 
node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
    int maxPathSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        res = INT_MIN;
        _dfs(root);

        return res;
    }
    int _dfs(TreeNode *root)
    {
        //1.recursion terminator
        if (root == NULL)
            return 0;

        //2.current level+3.drill down
        int left = _dfs(root->left);
        int right = _dfs(root->right);

        //!!!子路径大于0才加
        //a)这个node继续作为上个顶点的一个分支，所以在自己也只能选一条分支作为最长路径
        int cur_max_path1 = root->val;
        cur_max_path1 += std::max(left, right) > 0 ? std::max(left, right) : 0;
        //b)这个node加两个分支形成最终路径
        int cur_max_path2 = root->val +
                            (left > 0 ? left : 0) +
                            (right > 0 ? right : 0);

        int cur_max_path = std::max(cur_max_path1, cur_max_path2);
        if (cur_max_path > res)
            res = cur_max_path;

        //返回的是path1，因为path2已经看作是完整路径了，所以不能再加上面的结点
        return cur_max_path1;
    }

private:
    int res;
};
//dfs
//max_path(left)+max_path(right)