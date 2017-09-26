/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode *root)
    {
        inorder(root);
        for (int i = 0, j = nums_.size() - 1; i < j; ++i, --j)
        {
            if (nums_[i] != nums_[j])
            {
                return false;
            }
        }
        return true;
    }
    void inorder(TreeNode *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            nums_.push_back(root->val);
            inorder(root->right);
        }
    }

private:
    vector<int> nums_;
};

//solution 1
//inorder traverse and check if it's a palindrome string.
//time:O(2*N)
//space:O(N)
/*★ the method is wrong, if the tree is like this:
            1
        2       3
    3       2

*/

//solution 2
//recursion like a mirror
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode *p1, TreeNode *p2)
    {
        //1.recursion termiantor
        if (p1 == NULL && p2 == NULL)
        {
            return true;
        }
        else if (p1 == NULL || p2 == NULL)
        {
            return false;
        }
        //2.current level processing
        if (p1->val != p2->val)
        {
            return false;
        }

        //drill down
        return isMirror(p1->left, p2->right) && isMirror(p1->right, p2->left);
    }
};
//time:O(N)
//space:O(1)