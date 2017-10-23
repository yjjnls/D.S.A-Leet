/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to 
find the kth smallest frequently? How would you optimize the kthSmallest routine?

Credits:
Special thanks to @ts for adding this problem and creating all test cases.
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
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root);
        return nums_[k - 1];
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

//inorder tracerse
//time:O(N)
//space:O(N)

//solution 2 binary search
//time:O(log n)

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int num = countNodes(root->left);
        if ((num + 1) == k)
            return root->val;
        if ((num + 1) > k)
            return kthSmallest(root->left, k);
        if ((num + 1) < k)
            return kthSmallest(root->right, k - 1 - num);
    }
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        return countNodes(root->left) +
               countNodes(root->right) + 1;
    }
};

//感觉时间复杂度不止O(log n)，因为countNodes也是不断递归访问子树结点