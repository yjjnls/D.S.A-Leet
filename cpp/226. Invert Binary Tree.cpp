/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
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
    TreeNode *invertTree(TreeNode *root)
    {
        //recursion terminator
        //current level processing
        //drill down

        if (root == NULL)
        {
            return NULL;
        }

        std::swap(root->left, root->right);

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

//solution 2 no-recursion
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        std::stack<TreeNode *> stk;
        stk.push(root);

        while (!stk.empty())
        {
            TreeNode *p = stk.top();
            stk.pop();
            if (p)
            {
                stk.push(p->left);
                stk.push(p->right);
                std::swap(p->left, p->right);
            }
        }
        return root;
    }
};