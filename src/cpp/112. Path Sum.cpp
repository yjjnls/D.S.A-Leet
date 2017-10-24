/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode *root, int sum)
    {
        // recursion terminator
        if (root == NULL)
            return false;
        // current level processing
        if ((sum - root->val) == 0 &&
            root->left == NULL &&
            root->right == NULL)
            return true;
        // drill down
        bool res1 = hasPathSum(root->left, sum - root->val);
        bool res2 = hasPathSum(root->right, sum - root->val);

        return res1 || res2;
    }
};

/*
dfs

*/