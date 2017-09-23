/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode *root)
    {
        //1.recursion terminator
        if (root == NULL)
        {
            return 0;
        }
        //2.current level processing + 3.drill down
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

//1.BFS O(N)

//2.DFS O(N)

//3.DP f(N)=max( f(left)+f(right) )+1