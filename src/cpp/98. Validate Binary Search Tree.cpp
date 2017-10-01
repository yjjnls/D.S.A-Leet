/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.

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
    bool isValidBST(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        if (!isValidBST(root->left))
        {
            return false;
        }
        //pre_ is the max val of the left subtree
        if (root->val <= pre_)
        {
            return false;
        }
        else
        {
            pre_ = root->val;
        }

        if (!isValidBST(root->right))
        {
            return false;
        }
        return true;
    }

private:
    //c++11 permission
    /*use LONG_MIN instead of INT_MIN, if the input is just INT_MIN, it will be wrong.
    */
    long pre_ = LONG_MIN;
};
//time:O(N)
//1. inorder -> is increased array

//2.getMax(root->left)<=root  && root <= getMin(root->right)

bool isValidBST(TreeNode *root)
{
    return isValidBST(root, NULL, NULL);
}

bool isValidBST(TreeNode *root, TreeNode *minNode, TreeNode *maxNode)
{
    if (!root)
        return true;
    if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
        return false;
    return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}