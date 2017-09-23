/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined 
as a binary tree in which the depth of the two subtrees of 
every node never differ by more than 1.
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
    bool isBalanced(TreeNode *root)
    {
        //1.recursion terminator
        if (root == NULL)
        {
            return true;
        }

        //2.current level processing
        int depth1 = depth(root->left);
        int depth2 = depth(root->right);
        if (abs(depth1 - depth2) > 1)
        {
            return false;
        }

        //3.drill down
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int depth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return std::max(depth(root->left), depth(root->right)) + 1;
    }
};

//dp