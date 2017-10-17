/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        //1.terminator
        if (root == NULL)
            return res;
        //2.init container
        queue<TreeNode *> q;
        q.push(root);
        bool left2right = true;

        while (!q.empty())
        {
            int cur_size = q.size();
            vector<int> curr_level(cur_size);

            for (int i = 0; i < cur_size; ++i)
            {
                //3.pop node from container
                TreeNode *node = q.front();
                q.pop();
                //4.process current node
                int index = left2right ? i : cur_size - 1 - i;
                curr_level[index] = node->val;
                //5.push related nodes to container
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            //6.other work
            res.push_back(curr_level);
            left2right = !left2right;
        }

        return res;
    }
};