/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode *root)
    {
        //1.recursion terminator
        if (root == NULL)
        {
            return 0;
        }
        //2.current level processing + 3.drill down
        if (!root->left)
        {
            //★different from maxDepth, if one subtree is empty, it shouldn't be count(the depth will be 0)
            //while in maxDepth, the depth of subtree won't influecne the max value
            return 1 + minDepth(root->right);
        }
        if (!root->right)
        {
            return 1 + minDepth(root->left);
        }
        return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};
//time:O(N) N为树的结点数
//dp
class solution2
{
    int minDepth(TreeNode *root)
    {
        //1.recursion terminator
        if (root == NULL)
        {
            return 0;
        }
        //2.prepare data + 3.conquer subproblems
        int l_depth, r_depth;
        if (!root->left)
        {
            r_depth = minDepth(root->right);
            return 1 + r_depth;
        }
        if (!root->right)
        {
            l_depth = minDepth(root->left);
            return 1 + l_depth;
        }
        l_depth = minDepth(root->left);
        r_depth = minDepth(root->right);
        //4.process and gererate the final result
        return std::min(l_depth, r_depth) + 1;
    }
};