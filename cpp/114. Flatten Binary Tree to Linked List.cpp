/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child 
points to the next node of a pre-order traversal.
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
    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        TreeNode dummy(0);
        res_ = &dummy;
        preorder(root);
        root->left = NULL;
        root->right = dummy.right->right;
    }
    void preorder(TreeNode *root)
    {
        if (root != NULL)
        {
            TreeNode *node = new TreeNode(root->val);
            res_->right = node;
            res_ = res_->right;
            preorder(root->left);
            preorder(root->right);
        }
    }

private:
    TreeNode *res_;
};
//看似是简单的先序遍历，难点在于要在同一棵树上既遍历，又修改