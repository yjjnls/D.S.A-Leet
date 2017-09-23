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
        //2.current level processing + 3.
        if (!root->left)
        {
            //★different from maxDepth, 
            return 1 + minDepth(root->right);
        }
        if (!root->right)
        {
            return 1 + minDepth(root->left);
        }
        return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

//dp