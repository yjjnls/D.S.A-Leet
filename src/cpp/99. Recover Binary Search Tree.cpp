/*

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

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
    void recoverTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        prev = new TreeNode(INT_MIN);
        inorder(root);
        swap(p1->val, p2->val);
    }
    void inorder(TreeNode *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            if (p1 == NULL && root->val < prev->val)
            {
                p1 = prev;
            }
            if (p1 != NULL && root->val < prev->val)
            {
                p2 = root;
            }
            //下面这段代码错就错在当两个乱序的node是连着的时候，这里有个else，所以只会标记一次
            //种情况下应该把p1 p2都标记了
            // if (root->val < prev->val)
            // {
            //     if (p1 == NULL)
            //     {
            //         p1 = prev;
            //     }
            //     else
            //     {
            //         p2 = root;
            //     }
            // }
            prev = root;
            inorder(root->right);
        }
    }

private:
    TreeNode *p1 = NULL;
    TreeNode *p2 = NULL;
    TreeNode *prev = NULL;
};

/*
solution 1 
inorder travser 
*/


class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
    }

private:
};